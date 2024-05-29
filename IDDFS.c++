#include<iostream>
#define N 4
using namespace std;
bool isSafe(int maze[N][N],int x,int y)
{
    return (x>=0 && x<N && y>=0 && y<N && maze[x][y]==1);
}
bool dls(int maze[N][N],int x,int y,int sol[N][N],int limit)
{
    if(x==N-1 && y==N-1){
        sol[x][y]=1;
        return true;
    }

    if(limit<=0)
    {
        return false;
    }

    if(isSafe(maze,x,y))
    {
        sol[x][y]=1;
        if(dls(maze,x+1,y,sol,limit-1))
        {
            return true;
        }
        if(dls(maze,x,y+1,sol,limit-1))
        {
            return true;
        }
        sol[x][y]=0;
    }
    return false;
}

bool IDDFS(int maze[N][N],int sol[N][N],int maxsdepth)
{
    for(int depth=0;depth<=maxsdepth;depth++)
    {
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                sol[i][j]=0;
            }
        }
        if(dls(maze,0,0,sol,depth)){
            return true;
        }
    }
    return false;
}
void printboard(int sol[N][N])
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout<<sol[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int maze[N][N]={{ 1, 0, 0, 0 },
                        { 1, 1, 0, 1 },
                        { 0, 1, 0, 0 },
                        { 1, 1, 1, 1 } };
    int sol[N][N]={{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    int maxdepth=6;

    if(IDDFS(maze,sol,maxdepth))
    {
        cout<<"Solution exists\n";
        printboard(sol);
    }
    else
    {
        cout<<"solution doesn't exists";
    }
}