#include<bits/stdc++.h>
using namespace std;

int getMaxArea(vector<int> a){
    int n=a.size(),i=0,ans=0;
    stack<int> st;
    a.push_back(0);     //we put zero because this is the last element so anything multiply with 0 will become zero so it will handle the case of empty stack.
    while(i<n){
        while(!st.empty() and a[st.top()]>a[i]){
            //we get a potential area. so we calcualte it.
            int t=st.top();
            int h=a[t]; //height of potential area.
            st.pop();
            if(st.empty()){
                ans=max(ans, h*i);      //here i is the width of the rectangle formed.
            }
            else{
                ans=max(ans, h*(i-st.top()-1)); //here (i-st.top()-1) is the width of the recangle formed and it is because we are seeing the area of the rectangle formed left side also.
            }
        }
        st.push(i);
        i++;
    }
    return ans;
}

int main(){
    vector<int> a={2,1,5,6,2,3};
    cout<<getMaxArea(a);
    //ans is 10.
    return 0;
}   