#include<bits/stdc++.h>
void subset(vector<int> &num, vector<int>& ans, int i, int sum)
{
    if(i == num.size())
    {
        ans.push_back(sum);
        return;
    }
    
    subset(num, ans, i+1, sum + num[i]);
    subset(num, ans, i+1, sum);
}
vector<int> subsetSum(vector<int> &num)
{
    vector<int> ans;
    subset(num, ans, 0, 0);
    sort(ans.begin(), ans.end());
    return ans;
    
    
}