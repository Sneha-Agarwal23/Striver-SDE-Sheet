#include<bits/stdc++.h>
struct activity{
    int start;
    int finish;
};

bool comp(struct activity a, struct activity b)
{
    return a.finish < b.finish;
}
int maximumActivities(vector<int> &start, vector<int> &finish)
{
    int n = start.size();
    struct activity m[n];
    for(int i = 0; i < n; i++)
    {
        m[i].start = start[i];
        m[i].finish = finish[i];
    }
    sort(m, m+n, comp);
    int count = 1;
    int curtime = m[0].finish;
    for(int i = 1; i < n; i++)
    {
        if(m[i].start >= curtime)
        {
            count++;
            curtime = m[i].finish;
        }
    }
    return count;
}