#include<bits/stdc++.h>
struct job{
    int deadline;
    int profit;
};

bool comp(struct job a, struct job b)
{
    return a.profit > b.profit;
}
int jobScheduling(vector<vector<int>> &jobs)
{
    int n = jobs.size();
    struct job m[n];
    for(int i = 0; i < n; i++)
    {
        m[i].deadline = jobs[i][0];
        m[i].profit = jobs[i][1];
    }
    sort(m, m+n, comp);
    int maxdeadline = 0;
    for(int i = 0; i < n; i++)
    {
        maxdeadline = max(maxdeadline, m[i].deadline);
    }
    vector<int> slot(maxdeadline+1, -1);
    int maxprofit = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = m[i].deadline; j > 0; j--)
        {
            if(slot[j] == -1)
            {
                slot[j] = 0;
                maxprofit = maxprofit + m[i].profit;
                break;
            }
        }
    }
    return maxprofit;
    
}
