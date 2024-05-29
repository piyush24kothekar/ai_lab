#include <bits/stdc++.h>
using namespace std;

//  findZero function locates the position of the 0 (empty tile) in the initial state.
void findzero(vector<vector<int>> board, int &x, int &y){
    for (int i = 0; i < board.size(); i++){
        for (int j = 0; j < board.size(); j++){
            if (board[i][j] == 0){
                x = i;
                y = j;
                return;
            }
        }
    }
}
void printBoard(vector<vector<int>> &board){
    for (int i = 0; i < board.size(); i++){
        for (int j = 0; j < board.size(); j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

bool isGoalState(vector<vector<int>> &board, vector<vector<int>> &goal) {
        return board == goal;
}
// For each tile, the function checks if the tile in the current state (board[i][j]) is different from the tile in the goal state (goal[i][j]).
// If they are different, it means the tile is misplaced, and the count is incremented by 1.

int findMisplacedTiles(vector<vector<int>> &board, vector<vector<int>> &goal){
    int count = 0;
    for (int i = 0; i < board.size(); i++){
        for (int j = 0; j < board.size(); j++){
            if (board[i][j] != goal[i][j])
                count++;
        }
    }
    return count;
}
void aStar(vector<vector<int>> &board, vector<vector<int>> &goal, int depth, int x, int y){
    // This priority queue (pq) is used to store the states of the puzzle along with their priority values (sum of g and h). It ensures that the state with the lowest cost is processed first.
    priority_queue<pair<int, vector<vector<int>>>, vector<pair<int, vector<vector<int>>>>,
    greater<pair<int, vector<vector<int>>>>> pq;
    // pair<int, vector<vector<int>>>:
// Type: This specifies the type of elements that the priority queue will store. In this case, it stores pairs where:
// The first element of the pair (int) is the priority value (the sum of the g-cost and h-cost in the A* algorithm).
// The second element of the pair (vector<vector<int>>) is the current state of the puzzle board
    //vector<pair<int, vector<vector<int>>>>:-This specifies the underlying container that the priority queue will use to store its elements. Here, it is a vector of pairs. The priority_queue uses this vector to manage the heap structure internally.greater<pair<int, vector<vector<int>>>>:
// Comparator: This specifies the comparison criterion used to order the elements in the priority queue. The greater comparator is used to create a min-heap, which means that the element with the smallest priority value will be at the top of the queue.
// Without this comparator, the default behavior of a priority_queue is to create a max-heap, where the largest element is given the highest priority. By using greater, we invert this behavior to prioritize the smallest element, which is suitable for the A* algorithm.
// The priority_queue in the A* algorithm ensures that the puzzle state with the lowest combined cost (g + h) is always processed first. 

    int g = depth;
    int h = findMisplacedTiles(board, goal);
//     g is the cost from the start to the current node (initially equal to depth).
// h is the heuristic cost (number of misplaced tiles).
// The initial state of the board is pushed into the priority queue with its calculated cost.

    pq.push({(g + h), board});
    while (!pq.empty()){
        vector<vector<int>> curr = pq.top().second;
        pq.pop();
        printBoard(curr);
        int x, y;
        findzero(curr, x, y);//The position of the empty tile (0) is found in the current state.

        if (isGoalState(curr, goal)){
            // If the current state matches the goal state, the function prints a success message and returns.  
            cout << "Goal State Reached" << endl;
            return;
        }
        int dx[] = {0, 0, -1, 1};
        int dy[] = {1, -1, 0, 0};
        for (int i = 0; i < 4; i++){
            int newX = x + dx[i];
            int newY = y + dy[i];
            // The possible moves are defined using dx and dy arrays (right, left, up, down).
// For each move, the new position of the empty tile is calculated.
// If the new position is valid (within the bounds of the board), the tiles are swapped to generate a new state.
            if (newX >= 0 && newX < curr.size() && newY >= 0 && newY < curr.size()){
                swap(curr[x][y], curr[newX][newY]);
                // The cost g is incremented by 1.
// The heuristic cost h is recalculated for the new state.
                g = depth + 1;
                h = findMisplacedTiles(curr, goal);
                pq.push({(g + h), curr});
                swap(curr[x][y], curr[newX][newY]);
                // The new state along with its cost is pushed into the priority queue.
// The tiles are swapped back to restore the original state for the next iteration.

            }
        }
    }
    return;
}
int main() {
    vector<vector<int>> initial = {
    {2, 8, 3},
    {1, 6, 4},
    {7, 0, 5}
    };
    vector<vector<int>> goal = {
    {1, 2, 3},
    {8, 0, 4},
    {7, 6, 5}
    };
    int x, y;
    // The findZero function locates the position of the 0 (empty tile) in the initial state.
// It assigns the coordinates of 0 to x and y.
    findzero(initial, x, y);

    aStar(initial, goal, 0, x, y);
    return 0;
}