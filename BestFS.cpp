#include<bits/stdc++.h>
using namespace std;

void findzero(vector<vector<int>> board,int &x,int &y)
{   
    for(int i=0;i<board.size();i++)
    {
        for(int j=0;j<board.size();j++)
        {
            if(board[i][j]==0)
            {
                x=i;
                y=j;
                return;
            }
        }
    }
}

int findMisplacedTiles(vector<vector<int>> &board,vector<vector<int>> &goal)
{
    int cont=0;
    for(int i=0;i<board.size();i++)
    {
        for(int j=0;j<board.size();j++)
        {
            if(board[i][j]!=goal[i][j])
            {
                cont++;
            }
        }
    }
    return cont;
}
void printboard(vector<vector<int>> &board)
{
    for(int i=0;i<board.size();i++)
    {
        for(int j=0;j<board.size();j++)
        {
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
bool isGoalState(vector<vector<int>> &board,vector<vector<int>> &goal)
{
    return board==goal;
}
void astar(vector<vector<int>> board,vector<vector<int>> &goal,int depth,int &x,int &y)
{

    priority_queue<pair<int,vector<vector<int>>>,vector<pair<int,vector<vector<int>>>>,greater<pair<int,vector<vector<int>>>>> pq;
    int h=findMisplacedTiles(board,goal);
    pq.push({h,board});

    while(!pq.empty())
    {
        vector<vector<int>> curr=pq.top().second;
        pq.pop();
        printboard(curr);
        findzero(curr,x,y);

        if(isGoalState(curr,goal))
        {
            cout<<"goal is reached"<<endl;
            return ;
        }

        int dx[]={0,0,-1,1};
        int dy[]={1,-1,0,0};

        for(int i=0;i<4;i++)
        {
            int newX=x+dx[i];
            int newY=y+dy[i];
            if(newX>=0 &&  newX<curr.size() && newY>=0 && newY<curr.size())
            {
                swap(curr[x][y],curr[newX][newY]);

                h=findMisplacedTiles(curr,goal);
                pq.push({h,curr});

                swap(curr[x][y],curr[newX][newY]);
            }
        }
    }
    return ;
}
int main(){
    vector<vector<int>> initial={{2,8,3},{1,6,4},{7,0,5}};
    vector<vector<int>> goal={{1,2,3},{8,0,4},{7,6,5}};

    int x,y;
    findzero(initial,x,y);

    astar(initial,goal,0,x,y);
    return 0;
}