class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        /*int n = nums.size();
        vector<int> ans;
        unordered_map<int, int> m;
        for(int i = 0; i < n; i++)
        {
            m[nums[i]]++;
        }
        for(auto i : m)
        {
            if(i.second > n/3)
            {
                ans.push_back(i.first);
            }
        }
        return ans;*/
        
        int n = nums.size();        //Boyer Moore Voting Algorithm
        int num1 = -1, num2 = -1, count1 = 0, count2 = 0;
        
        //At max 2 majority element, at min 0 majority element
        
        for(int i = 0; i < n; i++)
        {
            if(nums[i] == num1)
                count1++;
            else if(nums[i] == num2)
                count2++;
            else if(count1 == 0)
            {
                num1 = nums[i];
                count1 = 1;
            }
            else if(count2 == 0)
            {
                num2 = nums[i];
                count2 = 1;
            }
            else
            {
                count1--;
                count2--;
            }
        }
        vector<int> ans;
        count1 = 0, count2 = 0;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] == num1)
                count1++;
            else if(nums[i] == num2)
                count2++;
        }
        if(count1 > n/3)
            ans.push_back(num1);
        if(count2 > n/3)
            ans.push_back(num2);
        return ans;
        
        
    }
};