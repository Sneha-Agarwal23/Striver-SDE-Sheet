class Solution {
public:
    void sortColors(vector<int>& nums)
    {
        /*int n = nums.size();
        int c1 = 0, c2 = 0, c3 = 0;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] == 0)
                c1++;
            else if(nums[i] == 1)
                c2++;
            else
                c3++;
        }
        for(int i = 0; i < c1; i++)
        {
            nums[i] = 0;
        }
        for(int i = 0; i < c2; i++)
        {
            nums[i + c1] = 1;
        }
        for(int i = 0; i < c3; i++)
        {
            nums[i+c1+c2] = 2;
        }*/
        
        int n = nums.size();
        int low = 0;
        for(int i = 0; i < n;)
        {
            if(nums[i] == 0)
            {
                swap(nums[low], nums[i]);
                low++;
                i++;
            }
            else if(nums[i] == 1)
                i++;
            else
            {
                swap(nums[i], nums[n-1]);
                n--;
            }
        }
        
        //sort(nums.begin(), nums.end());
        
    }
};