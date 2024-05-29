#include<iostream>
#include<vector>
using namespace std;

struct State{
    vector<int> queens;

    State(int n):queens(n,-1){};

    bool isSafe(int row,int col)
    {
        for(int prevRow=0;prevRow<row;prevRow++)
        {
            int prevCol=queens[prevRow];
            if(prevCol==col || abs(prevCol-col)==abs(prevRow-row))
            {
                return false;
            }
        }
        return true;
    }
};
void printchessboard(const State& state)
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
bool dfs(int row,int n,State& curr)
{
    if(row==n){
        cout<<"Solution found\n";
        printchessboard(curr);
        return true;
    }
    printf("\n");
    printchessboard(curr);
    for(int col=0;col<n;col++)
    {
        if(curr.isSafe(row,col))
        {
            curr.queens[row]=col;

            if(dfs(row+1,n,curr))
            {
                return true;
            }
            curr.queens[row]=-1;
        }
    }
    return false;
}
int main()
{
    int n=8;
    State initial(n);
    if(!dfs(0,n,initial))
    {
        cout<<"No solution found\n";
    }
    return 0;
}