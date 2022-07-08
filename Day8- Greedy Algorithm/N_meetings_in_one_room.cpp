#include<bits/stdc++.h>
struct meeting{
    int id;
    int starttime;
    int endtime;
};

bool comp(struct meeting a, struct meeting b)
{
    if(a.endtime == b.endtime)
        return a.id < b.id;
    else
        return a.endtime < b.endtime;
}
vector<int> maximumMeetings(vector<int> &start, vector<int> &end)
{
    vector<int> ans;
    int n = start.size();
    struct meeting m[n];
    for(int i = 0; i < n; i++)
    {
        m[i].id = i+1;
        m[i].starttime = start[i];
        m[i].endtime = end[i];
    }
    sort(m, m+n, comp);
    ans.push_back(m[0].id);
    int currtime = m[0].endtime;
    for(int i = 1; i < n; i++)
    {
        if(m[i].starttime > currtime)
        {
            ans.push_back(m[i].id);
            currtime = m[i].endtime;
        }
    }
    return ans;
    
}