#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct State
{   
    vector<int> queens;
    State(int n):queens(n,-1){};

    bool isSafe(int row,int col){
        for(int prevRow=0;prevRow<row;prevRow++)
        {
            int prevCol=queens[prevRow];

            if(prevCol==col || abs(prevRow-row)==abs(prevCol-col))
            {
                return false;
            }
        }
        return true;
    }
};

void printchessboard(const State &state)
{
    for(int row=0;row<state.queens.size();row++)
    {
        for(int col=0;col<state.queens.size();col++)
        {
            if(state.queens[row]==col)
            {
                cout<<"Q ";
            }
            else
            {
                cout<<". ";
            }
        }
        cout<<endl;
    }
    cout<<endl;
}
bool solveNqueens(int n)
{
    queue<State> q;

    q.push(State(n));
    while(!q.empty())
    {
        State curr=q.front();
        q.pop();
        printchessboard(curr);

        int row=0;
        while(row< n && curr.queens[row]!=-1)
        {
            ++row;
        }

        if(row==n)
        {
            printf("solution found\n");
            printchessboard(curr);
            return true;
        }

        for(int col=0;col<n;col++)
        {
            if(curr.isSafe(row,col))
            {
                State nextState=curr;
                nextState.queens[row]=col;
                q.push(nextState);
            }
        }

        cout<<"Solution not found\n";
        return false;
    }

}

int main()
{
    int n=8;
    solveNqueens(n);
    return 0;
}