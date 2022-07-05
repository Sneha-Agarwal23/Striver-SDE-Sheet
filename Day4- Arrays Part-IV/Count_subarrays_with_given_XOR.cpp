#include <bits/stdc++.h> 
int subarraysXor(vector<int> &arr, int x)
{
    /*unordered_map<int, int> m;
    int count = 0;
    int xorr = 0;
    for(int i = 0; i < arr.size(); i++)
    {
        xorr = xorr ^ arr[i];
        if(xorr == x)
            count++;
        if(m.find(xorr ^ arr[i]) != m.end())
        {
            count = count + m[xorr ^ x];
        }
        m[xorr]++;
    }
    return count;*/
    
    int count = 0;		//TLE- Brute force
    for(int i = 0; i < arr.size(); i++)
    {
        int sum = 0;
        for(int j = i; j < arr.size(); j++)
        {
            sum = sum ^ arr[j];
            if(sum == x)
                count++;
        }
    }
    return count;
}