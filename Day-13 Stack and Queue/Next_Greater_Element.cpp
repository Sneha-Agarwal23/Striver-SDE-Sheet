#include<bits/stdc++.h>
vector<int> nextGreater(vector<int> &arr, int n) 
{
    /*vector<int> ans(n, -1);
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(arr[i] < arr[j])
            {
                ans[i] = arr[j];
                break;
            }
        }
    }
    return ans;*/
    
    stack<int> s;
    vector<int> ans(n);
    for(int i = n-1; i >= 0; i--)
    {
        while(!s.empty() && s.top() <= arr[i])
        {
           s.pop();
        }
        if(!s.empty())
        {
            ans[i] = s.top();
        }
        else
        {
            ans[i] = -1;
        }
        s.push(arr[i]);
    }
    return ans;
    

}