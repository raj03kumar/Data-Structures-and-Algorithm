#include<bits/stdc++.h>
using namespace std;

int rain_water(vector<int> a){
    stack <int> st;
    int ans=0;
    for(int i=0; i<a.size(); i++){
        while(!st.empty()&&a[st.top()]<a[i]){
            // means a water container is formed.
            int curr=st.top();
            st.pop();
            if(st.empty()){
                //means there is no big element on the right hand side to support the container so the ans is zero. we break the loop and come out.
                break;
            }
            else{
                int diff=i-st.top()-1;
                //here a[st.top()] is the left wall and a[i] is the right wall. of the container.
                ans+=(min(a[st.top()], a[i])-a[curr])*diff; //here diff is the width and other one is height
            }
        }
        st.push(i);
    }
    return ans;
}

int main(){
    vector<int> a={0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<rain_water(a);
    //ans is 6.
    return 0;
}   