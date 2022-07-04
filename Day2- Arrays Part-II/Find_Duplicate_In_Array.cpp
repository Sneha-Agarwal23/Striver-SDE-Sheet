class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        /*int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans;
        for(int i = 0; i < n-1; i++)
        {
            if(nums[i] == nums[i+1])
                ans = nums[i];
        }
        return ans;*/
        
        /*int slow = nums[0];
        int fast = nums[0];
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);
        fast = nums[0];
        while(slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;*/
        
        int ans;
        int n = nums.size();
        vector<int> c(n,0);
        for(int i = 0; i < n; i++)
        {
            c[nums[i]]++;
        }
        for(int i = 0; i < c.size(); i++)
        {
            if(c[i] > 1)
            {
                ans = i;
                break;
            }
        }
        return ans;

    unordered_map<int, int> m;
    for(int i = 0; i < n; i++)
    {
        m[arr[i]]++;
    }
    for(auto i : m)
    {
        if(i.second > 1)
            return i.first;
    }
	return -1;
    }
};