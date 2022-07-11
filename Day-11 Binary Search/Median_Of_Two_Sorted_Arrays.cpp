#include<bits/stdc++.h>
double median(vector<int> a, vector<int> b)
{
    vector<int> temp;
    int n = a.size();
    int m = b.size();
    for(int i = 0; i < n; i++)
    {
        temp.push_back(a[i]);
    }
    for(int i = 0; i < m; i++)
    {
        temp.push_back(b[i]);
    }
    sort(temp.begin(), temp.end());
    if(temp.size() % 2 == 1)
        return temp[temp.size()/2];
    double x = temp[temp.size()/2] + temp[temp.size()/2 - 1];
    return x/2;
}
