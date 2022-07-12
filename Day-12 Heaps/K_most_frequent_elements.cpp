#include<bits/stdc++.h>
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    priority_queue<pair<int, int>> pq;
    unordered_map<int, int> m;
    vector<int> ans;
    for(int i = 0; i < n; i++)
    {
        m[arr[i]]++;
    }
    for(auto i : m)
    {
        pq.push({i.second, i.first});
    }
    while(k > 0)
    {
        ans.push_back(pq.top().second);
        pq.pop();
        k--;
    }
    sort(ans.begin(), ans.end());
    return ans;
    
}