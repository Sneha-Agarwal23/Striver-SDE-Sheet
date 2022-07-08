#include<bits/stdc++.h>
bool comp(pair<int, int>& a, pair<int, int>& b)
{
    double x = (double)a.second/a.first;
    double y = (double)b.second/b.first;
    return x > y;
}
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    sort(items.begin(), items.end(), comp);
    int curwt = 0;
    double maxval = 0;
    for(int i = 0; i < n; i++)
    {
        if(curwt + items[i].first <= w)
        {
            curwt = curwt + items[i].first;
            maxval = maxval + items[i].second;
        }
        else
        {
            double f = items[i].second * ((double)(w - curwt)/ items[i].first);
            maxval = maxval + f;
            break;
        }
    }
    return maxval;
}