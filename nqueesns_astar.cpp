#include<queue>
#include<iostream>
#include<cmath>
#include<vector>

using namespace std;


struct State{
    vector<int> queens;
    int calHeuristics()const{
        int heuristics=0;
        int n=queens.size();

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(queens[i]==queens[j] || abs(i-j)==abs(queens[i]-queens[j]))
                {
                    heuristics++;
                }
            }
        }
        return heuristics;
    }

    bool operator<(const State& other) const{
        return calHeuristics()>other.calHeuristics();
    }
};

bool solveQueens(int n)
{
    priority_queue<State> pq;
    State initial;
    initial.queens.resize(n);
    pq.push(initial);

    while (!pq.empty())
    {
        State curr=pq.top();
        pq.pop();

        if(curr.calHeuristics()==0){
            //solution found
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    cout<<(curr.queens[i]==j?"Q ":". ");
                }
                cout<<endl;
            }
            return true;
        }

    //trying to place a queen in all possible places
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                State next=curr;
                next.queens[i]=j;
                pq.push(next);
            }
        }
    }

    return false;
}
int main(){
    int n;
    cout<<"Enter the number of queens: ";
    cin>>n;
    if(solveQueens(n)){
        cout<<"Solution exists!."<<endl;
    }
    else{
        cout<<"Solutions doesn't exists"<<endl;
    }
}