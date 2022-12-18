#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int> &a, int n, int i){
    int maxIdx=i;
    int l=2*i+1;
    int r=2*i+2; //for left and right childrens

    if(l<n and a[l]>a[maxIdx]){
        maxIdx=l;
    }
    if(r<n and a[r]>a[maxIdx]){
        maxIdx=r;
    }
    if(maxIdx!=i){
        swap(a[i], a[maxIdx]);
        heapify(a, n, maxIdx);
    }
}

void heapsort(vector<int> &a ){
//generally we should take vector by reference and it reduces the time complexity
    int n=a.size();
    for(int i=n/2-1; i>=0; i--){
        heapify(a, n, i);
    }
    for(int i=n-1; i>0; i--){
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

int main(){
    int n; cin>>n;

    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    heapsort(arr);
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}