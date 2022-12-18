//N-queens problem
#include<bits/stdc++.h>
using namespace std;

bool isSafe(int **arr, int x, int y, int n){
    //we have to check for column
    for(int row=0; row<x; row++){       //remember vertical is y so we fix y or draw a line y and check for other rows by iterating in the same fixed column.
        if(arr[row][y]==1){
            return false;
        }
    }
    //for diagonals. one is row-- and column-- ; it is right u have to visualize
    int row=x;
    int col=y;
    while(row>=0 and col>=0){
        if (arr[row][col]==1) return false;
        row--;
        col--;
    }
    // and other one is row-- column ++ ; it is right u have to visualise.
    row=x;
    col=y;
    while(row>=0 and col<n){
        if (arr[row][col]==1) return false;
        row--;
        col++;
    }
    return true;
}

bool nQueens(int **arr, int x, int n){      //we dont need y here because we dont need ot check the lower hemisphere.
    //base condition
    if(x>=n){       //means we have placed our n queens
        return true;
    }
    for(int col=0; col<n; col++){
        if(isSafe(arr, x, col, n)){
            arr[x][col]=1;
            //we again check 
            if(nQueens(arr, x+1, n)){
                return true;
            }
            //else
            arr[x][col]=0;      //backtracking
        }
    }
    return false;
}

int main(){
    int n; cin>>n;
    int **arr=new int *[n];
    for(int i=0; i<n; i++){
        arr[i]=new int[n];
        for(int j=0; j<n;j++){
            arr[i][j]=0;
        }
    }
    //now check if n queens returns true. if yes then we will print our array.
    if(nQueens(arr, 0, n)){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}