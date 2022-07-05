#include <bits/stdc++.h> 
int LongestSubsetWithZeroSum(vector < int > arr) 
{
    int n = arr.size();
    int length = 0;
    for(int i = 0; i < n; i++)
    {
        int sum = 0;
        for(int j = i; j < n; j++)
        {
            sum = sum + arr[j];
            if(sum == 0)
                length = max(length, j - i + 1);
        }
    }
    return length;

}