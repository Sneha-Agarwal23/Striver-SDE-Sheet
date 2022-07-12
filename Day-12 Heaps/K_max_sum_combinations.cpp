#include<bits/stdc++.h>
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k)
{
    priority_queue<int> pq;
    vector<int> ans;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            pq.push(a[i] + b[j]);
        }
    }
    for(int i = 0; i < k; i++)
    {
        int a = pq.top();
        pq.pop();
        ans.push_back(a);
    }
    return ans;
    
}