#include<iostream>
#include<vector>
using namespace std;

void printSolution(vector<vector<int>> &board, int n){
    for(int i=0; i<n; i++){
        for(int j = 0; j<n; j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool isSafe(int row, int col, vector<vector<int>>&board, int n){
    //check krna chahte hai ki kya mai current 
    //cell[row,col] pr queen rakh sakta hu ya nahi

    int i = row;
    int j = col;

    //check row
    while(j>=0){
        if(board[i][j] ==1){
            return false;
        }
        j--;
    }

    //check upper left digonal
    i = row;
    j = col;

    while(i>= 0 && j>=0){
        if(board[i][j] == 1){
            return false;
        }
        i--;
        j--;
    }

    //check bottom left diagonal
    i = row;
    j = col;

    while(i<n && j>=0){
        if(board[i][j] == 1){
            return false;
        }
        i++;
        j--;
    }

    ///kahin pr bhi queen nahi mili iska matlab ye position safe hai iska mtlb return true krdo
    return true;
}

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