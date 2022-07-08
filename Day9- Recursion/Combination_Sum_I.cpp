#include<bits/stdc++.h>
void combo1(vector<int>& arr, int n, int k, vector<vector<int>>& ans, 
vector<int>& v, int index)
{
    if(index == n)
    {
        if(k == 0)
        {
            ans.push_back(v);
        }
        return;
    }
    
    combo1(arr, n, k, ans, v, index+1);
    v.push_back(arr[index]);
    combo1(arr, n, k - arr[index], ans, v, index+1);
    v.pop_back();
}
vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    vector<vector<int>> ans;
    vector<int> v;
    combo1(arr, n, k, ans, v, 0);
    return ans;
}