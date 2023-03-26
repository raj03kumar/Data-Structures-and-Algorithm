/*
Given q queries, of 3 types:
    1. Insert a number X into the set
    2. Print the k'th element
    3. Print the number of elements less than k
*/
#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){
    int q; cin>>q;
    oset<int> s;
    while(q--){
        int c; cin>>c;
        if(c==1){
            // to insert the element in set
            int t; cin>>t;
            s.insert(t);
        }
        else if(c==2){
            // to find the k'th element in the set
            int t; cin>>t;
            cout<<*s.find_by_order(t)<<endl;
        }
        else{
            //to find how many numbers are smaller than k
            int t; cin>>t;
            cout<<s.order_of_key(t)<<endl;
        }
    }
    return 0;
}

/*
INPUT:
7
1 1
1 2
1 4
2 1
2 <-- output
1 8
1 16
3 4
2 <-- output
*/