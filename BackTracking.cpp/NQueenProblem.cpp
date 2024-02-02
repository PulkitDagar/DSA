#include<iostream>
#include<vector>
using namespace std;

void solve(vector<vector<int>> &board, int col, int n){
    //base case

    if(col>=n){
        printSolution(board,n);
        return;
    }

    //1 case solve krdo baaki recursion sambhal lega
    for(int row = 0; row<n; row++){
        if(isSafe(row,col,board,n)){

            //rakh do
            board[row][col] = 1;

            ///recursion solution laega
            solve(board, col+1, n);

            //backtracking
            board[row][col] = 0;
        }
    }

};


int main(){
    int n = 4;
    vector<vector<int>>board(n, vector<int>(n,0));
    int col = 0;

    //0-> empty cell
    //1 -> queen at the cell

    solve(board,col,n);

    return 0;
}