#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    //kadanes' algorithm
    //we have to find max subarray sum of the difference of the prices.
    //same as daily change in stock market PnL.
    int curr_sum=0, max_sum=0;
    //imagine we bought on day 1 sp we put day1 as 0
    for(int i=1; i<prices.size(); i++){
        curr_sum=max(0, curr_sum+=prices[i]-prices[i-1]);
        max_sum=max(max_sum, curr_sum);
    }
    return max_sum;
}
int main(){
    vector<int> prices={7, 8, 9, 0, 10, 12};
    cout<<"The maximum profit is: "<<maxProfit(prices);
    //This question can be also solved using stack and the problem is known as Stock Span Problem
    return 0;
}