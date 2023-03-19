/*
Q. A group of cows grabbed a truck and ventured on an expedition deep into the jungle. The truck leak 1 unit of fuel every unit of distance it travels.
To repair the truck, the cows need to drive to the nearest town(no more than 10^6 unit distance). On this road between the town and the current location, there are N stops where the cows can stop to acquire additional fuel.
The cows want to make MINIMUM POSSIBLE NUMBER OF STOPS FOR FUEL ON THE WAY TO TOWN.
Capacity of the tank is sufficiently large to hold any amount of fuel.

Initial unit of fuel: P
Initial distance from Town: L

Determine minimum number of stops to reach the town ?

NOTE: Better we find the distance from truck so see which stop is close to truck
*/

/*
BRUTE FORCE:
    1. Generate all subsequence of stops.
    2. Iterate over all subsequence, choose the one that is feasible and has minimum no of stops.

    Time Complexity: O(2^n) --> TLE

OPTIMAL SOLUTION:
    1. Create a maxheap, which stores the fuels available at the stops that we have traversed.
    2. Sort the stops, on the basis of distance of stops from inital position of truck.
    3. Keep iterating on the stops, and whenever fuel in the truck becomes empty, take the fuel from the max-heap and add it to the truck(greedy step).
    4. Maintain the count of stops from which we have taken fuel.
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;

        vector<pair<int, int>>a(n);
        for(int i=0; i<n; i++){
            cin>>a[i].first>>a[i].second;
        }

        int l, p; cin>>l>>p;
        //for converting distance from truck rather than from town.
        for(int i=0; i<n; i++){
            a[i].first=l-a[i].first;
        }

        sort(a.begin(), a.end());
        int ans = 0;
        int curr = p;

        priority_queue<int, vector<int>>pq;
        bool flag = 0;
        for(int i=0; i<n; i++){
            if(curr>=l){
                break;
            }

            while(curr < a[i].first){
                if(pq.empty()){
                    flag=1;
                    break;
                }
                ans++;
                curr+=pq.top();
                pq.pop();
            }
            if(flag) break;

            pq.push(a[i].second);           
        }
        if(flag){
                cout<<"-1"<<endl;
                continue;
        }
        while(!pq.empty() and curr<l){
            curr+=pq.top();
            pq.pop();
            ans++;
        }
        if(curr<l){
            cout<<"-1"<<endl;
            continue;
        }
        cout<<ans<<endl;
    }
    return 0;
}

/*
INPUT:
1
4
4 4
5 2 
11 5
15 10
25 10
*/

/*
OUTPUT: 2
*/