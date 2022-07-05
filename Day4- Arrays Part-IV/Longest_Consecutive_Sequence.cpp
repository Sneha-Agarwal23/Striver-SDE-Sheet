#include <bits/stdc++.h> 
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n)
{
    sort(arr.begin(), arr.end());
    int length = 0;
    int count = 1;
    for(int i = 0; i < n-1; i++)
    {
        if(arr[i] + 1 == arr[i+1])
            count++;
        else if(arr[i] == arr[i+1])
            continue;
        else
        {
            length = max(length, count);
            count = 1;
        }
    }
    return max(length, count);
    
}