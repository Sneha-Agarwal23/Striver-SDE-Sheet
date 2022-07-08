#include<bits/stdc++.h>
void solve(vector<int> &arr, int n, int target, vector<vector<int>>& ans, vector<int>& v, int i)
{
    if(target == 0)
    {
        ans.push_back(v);
        return;
    }
    
    for(int j = i; j < arr.size(); j++)
    {
        if(j > i && arr[j] == arr[j-1])
            continue;
        if(arr[j] <= target)
        {
            v.push_back(arr[j]);
            solve(arr, n, target-arr[j], ans, v, j+1);
            v.pop_back();
        }
    }
}
vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
	vector<vector<int>> ans;
    vector<int> v;
    sort(arr.begin(), arr.end());
    solve(arr, n, target, ans, v, 0);
    return ans;
    
}
