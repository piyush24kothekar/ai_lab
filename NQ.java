package PracticeAlLabExam;

import java.util.Scanner;

public class NQ
{
    static int solutionCount;
    static int n;
    static int chessboard[][];
    public static void main(String[] args) {
        Scanner sc =new Scanner(System.in);
        System.out.println("enter the size of chessboard");
        n=sc.nextInt();
        chessboard=new int[n][n];
        solveNQueens(0);
        System.out.println("Total solutions"+solutionCount);
        sc.close();
    }

    public static boolean isSafe(int row,int col)
    {
        for(int j=col;j>=0;j--)
        {
            if(chessboard[row][j]==1)
            {
                return false;
            }
        }

        int i=row,j=col;
        while (i>=0 && j>=0) {
            if(chessboard[i][j]==1)
            {
                return false;
            }
            i--;
            j--;
        }

        i=row;
        j=col;
        while (i<n && j>=0) {
            if(chessboard[i][j]==1)
            {
                return false;
            }
            i++;
            j--;
        }


        return true;
    }

    public static void printChessboard()
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(chessboard[i][j]==1)
                {
                    System.out.print("Q ");
                }
                else
                {
                    System.out.print(". ");
                }
            }
            System.out.println();
        }
        System.out.println();
    }
    public static void solveNQueens(int currentColumn)
    {
        if(currentColumn>=n){return;}
        for(int row=0;row<n;row++)
        {
            if(isSafe(row,currentColumn))
            {
                chessboard[row][currentColumn]=1;
                if(currentColumn==n-1)
                {
                    printChessboard();
                    solutionCount++;
                }
                solveNQueens(currentColumn+1);
                chessboard[row][currentColumn]=0;
            }
        }
    }
}