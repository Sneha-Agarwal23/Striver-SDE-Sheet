#include<bits/stdc++.h>
int uniqueElement(vector<int> arr, int n)
{
	/*unordered_map<int, int> m;        TLE
    for(int i = 0; i < n; i++)
    {
        m[arr[i]]++;
    }
    for(auto i : m)
    {
        if(i.second == 1)
            return i.first;
    }
    return -1;*/
    
    /*for(int i = 0; i < n; i++)
    {
        if(arr[i] != arr[i+1])
            return arr[i];
        i++;
    }*/
    
    /*int low = 0;
    int high = n-1;
    int mid;
    while(low < high)
    {
        mid = (low + high)/2;
        if((mid % 2 == 1 && arr[mid] == arr[mid-1]) || (mid % 2 == 0 && arr[mid] == arr[mid+1]))
        {
            low = mid + 1;
        }
        else
            high = mid;
    }
    return arr[low];*/
    
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        ans = ans ^ arr[i];
    }
    return ans;
}
