//rat in maze BACK-TRACKING using recursion
//easy hai ye kaafi...just u should know to code what are you thinking.
#include<bits/stdc++.h>
using namespace std;

bool isSafe(int **arr, int x, int y, int n){
    if(x<n && y<n && arr[x][y]==1){
        return true;
    }
    return false;
}

bool ratinMaze(int** arr, int x, int y, int n, int** solArr){   
    //x means x right direction, y means down.
    //base condition: i.e. when the rat reaches the position just before the end line.
    if((x==n-1) && (y==n-1)){
        solArr[x][y]=1;
        return true;
    }
    if(isSafe(arr, x,y,n)){
        solArr[x][y]=1;
        if(ratinMaze(arr,x+1, y,n,solArr)){ //check if rat can move right
            return true;
        }
        if(ratinMaze(arr, x,y+1, n, solArr)){ //check if rat can move down
            return true;
        }
        solArr[x][y]=0; //backtracking
        return false;
    }
    return false;
}

int main(){
    int n; cin>>n;

    int **arr=new int*[n]; //dynamically allocate 2D array.
    for(int i=0; i<n;i++){
        arr[i]=new int[n];
    }
    //taking input in array.

    for(int i=0; i<n; i++){
        for(int j=0; j<n;j++){
            cin>>arr[i][j];
        }
    }

    //we will be implementing sol array also through dynamic allocation
    int **solArr=new int*[n];
    for(int i=0; i<n;i++){
        solArr[i]=new int[n];
    }
    for(int i=0; i<n; i++){     //initialising all the value to zero in solution array.
        for(int j=0; j<n;j++){
            solArr[i][j]=0;
        }
    }
    cout<<endl;
    if(ratinMaze(arr, 0, 0, n, solArr)){
        //if rat in maze returns true then print the array. else print rat is trapped.
        for(int i=0; i<n; i++){
            for(int j=0; j<n;j++){
                cout<<solArr[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    return 0;
}
