#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices)
{
    int maxprofit = 0;
    int minprice = prices[0];
    for(int i = 0; i < prices.size(); i++)
    {
        minprice = min(minprice, prices[i]);
        maxprofit = max(maxprofit, prices[i] - minprice);
    }
    return maxprofit;
    
}