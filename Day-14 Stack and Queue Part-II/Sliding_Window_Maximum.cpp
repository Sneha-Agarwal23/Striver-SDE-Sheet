#include<bits/stdc++.h>
vector<int> slidingWindowMaximum(vector<int> &nums, int &k)
{
    vector<int> ans;
    int n = nums.size();
    for(int i = 0; i <= n-k; i++)
    {
        int maxi = nums[i];
        for(int j = 1; j < k; j++)
        {
            if(nums[i+j] > maxi)
                maxi = nums[i+j];
        }
        ans.push_back(maxi);
    }
    return ans;
   
}