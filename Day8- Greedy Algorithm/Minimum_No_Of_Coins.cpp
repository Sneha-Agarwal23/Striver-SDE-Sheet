#include<bits/stdc++.h>
int findMinimumCoins(int amount) 
{
    vector<int> den = {1,2,5,10,20,50,100,500,1000};
    int n = den.size();
    int count = 0;
    for(int i = n - 1; i >= 0; i--)
    {
        while(amount >= den[i])
        {
            amount = amount - den[i];
            count++;
        }
    }
    return count;
}


