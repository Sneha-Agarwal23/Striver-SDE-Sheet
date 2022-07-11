#include<bits/stdc++.h>
int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k)
{
    vector<int> temp;
    for(int i = 0; i < m; i++)
    {
        temp.push_back(row1[i]);
    }
    for(int i = 0; i < n; i++)
    {
        temp.push_back(row2[i]);
    }
    sort(temp.begin(), temp.end());
    return temp[k - 1];
    
}