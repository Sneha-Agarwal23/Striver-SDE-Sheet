//Leetcode

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        for(int i = 0; i < n-3; i++)
        {
            for(int j = i+1; j < n-2; j++)
            {
                int new_target = target - nums[i] - nums[j];
                int front = j+1;
                int back = n-1;
                while(front < back)
                {
                    if(nums[front] + nums[back] < new_target)
                        front++;
                    else if(nums[front] + nums[back] > new_target)
                        back--;
                    else
                    {
                        result.push_back(vector<int> {nums[i], nums[j], nums[front], nums[back]});
                        front++;
                        back--;
                        while(front < back && nums[front] == result.back()[2])
                            front++;
                        while(front < back && nums[back] == result.back()[3])
                            back--;
                    }
                }
                while(j+1 < n && nums[j] == nums[j+1])
                    j++;
            }
            while(i+1 < n && nums[i] == nums[i+1])
                i++;
        }
        return result;
    }
};



//Coding Ninja
#include <bits/stdc++.h> 
string fourSum(vector<int> arr, int target, int n)
{
    unordered_map<int, pair<int, int>> m;
    for(int i = 0; i < n-1; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            int sum = arr[i] + arr[j];
            m[sum] = {i,j};
        }
    }
    for(int i = 0; i < n-1; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            int left = target - (arr[i] + arr[j]);
            if(m.find(left) != m.end())
            {
                pair<int, int> it = m[left];
                int k = it.first;
                int l = it.second;
                
                if(i != k &&  i != l && j != k && j != l)
                    return "Yes";
            }
        }
    }
    return "No";
    
}
