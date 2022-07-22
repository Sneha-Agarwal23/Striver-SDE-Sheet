#include<bits/stdc++.h>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
   /*vector<int> ans(n, -1);
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(arr[i] > arr[j])
            {
                ans[i] = arr[j];
                break;
            }
        }
    }
    return ans;*/
    
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for(int i = n-1; i >= 0; i--)
    {
        while(s.top() >= arr[i])
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(arr[i]);
    }
    return ans;
    
}