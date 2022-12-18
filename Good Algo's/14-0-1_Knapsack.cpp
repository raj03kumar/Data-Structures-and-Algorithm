//0-1 knapsack problem using recursion.(Greedy method) because it is an optimisation problem.

/*
put n items with a given weightand value in a knapsackof capacity W to get the maximum total value in the knapsack. Note: we can take fractions also of the objects in normal knapsack problem. BUT IN 0-1 KNAPSACK PROBLEM WE CAN'T TAKE FRACTIONS. WE HAVE TO EITHER TAKE FULL OR NONE.

Question statement:
We are given some objects and each object has some profit and some weight(w) associated with it. We are given a bag called knapsack who's weight is W. so we have to put the objects in the bag and sell away the items so we get maximum profit.

Approach: we find out price per kg of the object. and put all the objects who's price per weight is highest and then move to another object and so on. 
*/

/*
So using recursion we find for all items that should we include it in our knapsack or not.

--------W=50 KG----where W is weight of knapsack. wt is weight of item. value is value of item.
i           0       1       2
wt[i]       10     20       30
value[i]    100    50       150

*/

#include<bits/stdc++.h>
using namespace std;

int knapsack(int value[], int wt[], int n, int W){
    // so if we include that item then
    //[n-1] because here we are going in opposite order.
    //knapsack(value, wt, n-1, W-wt[n-1])+ value[n-1]; //--> this represent the value if we include nth item 

    //so if we are not including that item then
    //knapsack(value, wt, n-1, W); //-->this represent the value if we dont include nth item.

    if(n==0 or W==0){       //base conditions
        return 0;
    }
    if(wt[n-1]>W){
        //so we can't include that element so we return that
        return knapsack(value, wt, n-1, W);
    }

    return max(knapsack(value, wt, n-1, W-wt[n-1])+ value[n-1],knapsack(value, wt, n-1, W) ); //note here we are storing the value as well.
}

int main(){
    int wt[]={10,20,30};
    int value[]={100, 50, 150};
    int W=50;

    cout<<knapsack(value, wt, 3, W)<<"\n";

    return 0;
}