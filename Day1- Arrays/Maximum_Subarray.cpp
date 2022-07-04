class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        /*int currentSum = nums[0];
        int maxSum = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            currentSum = currentSum + nums[i];
            if(nums[i] > currentSum)
                currentSum = nums[i];
            if(currentSum > maxSum)
                maxSum = currentSum;
        }
        return maxSum;*/
        
        int n = nums.size();
        int maximum = INT_MIN;
        for(int i = 0; i < n; i++)
        {
            int sum = 0;
            for(int j = i; j < n; j++)
            {
                sum = sum + nums[j];
                maximum = max(sum, maximum);
            }
        }
        return maximum;
        
    }
};