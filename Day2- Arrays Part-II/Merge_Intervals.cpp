#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    vector<vector<int>> ans;
    sort(intervals.begin(), intervals.end());
    int n = intervals.size();
    ans.push_back(intervals[0]);
    for(int i = 1; i < n; i++)
    {
        auto &prev = ans[ans.size()-1];
        auto next = intervals[i];
        if(prev[1] >= next[0])
        {
            prev[1] = max(prev[1], next[1]);
        }
        else
        {
            ans.push_back(next);
        }
    }
    return ans;
}
