#include<iostream>
#define N 4
#define LIMIT 6
using namespace std;

bool isSafe(int maze[N][N],int x,int y){
    return (x>=0 && x<N && y>=0 && y<N && maze[x][y]==1);
}
bool dfslimited(int maze[N][N],int x,int y,int sol[N][N],int limit)
{
    if(x==N-1 && y==N-1){
        sol[x][y]=1;
        return true;
    }

    if(limit<=0){
        return false;
    }
    if(isSafe(maze,x,y))
    {
        sol[x][y]=1;

        if(dfslimited(maze,x+1,y,sol,limit-1)){
            return true;
        }

        if(dfslimited(maze,x,y+1,sol,limit-1)){
            return true;
        }
        sol[x][y]=1;
    }
    return false;
}
void printboard(int soln[N][N])
{   
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout<<soln[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{

    int maze[N][N]={{1,1,1,0},{0,1,0,0},{1,1,1,0},{1,1,1,1}};
    int soln[N][N]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};

    if(dfslimited(maze,0,0,soln,LIMIT)==false)
    {
        cout<<"Solution doesn't exists";
    }
    else
    {
        cout<<"Solution exists:\n";
        printboard(soln);
    }
}