#include <bits/stdc++.h> 
int findMajorityElement(int arr[], int n) 
{
    unordered_map<int, int> m;
    int ans = -1;
    for(int i = 0; i < n; i++)
    {
        m[arr[i]]++;
    }
    for(auto i : m)
    {
        if(i.second > n/2)
        {
            ans = i.first;
            break;
        }
    }
    return ans;
    
    /*int count = 0;
    int element = 0;
    for(int i = 0; i < n; i++)
    {
        if(count == 0)
            element = arr[i];
        if(element == arr[i])
            count++;
        else
            count--;
    }
	return element;*/
}