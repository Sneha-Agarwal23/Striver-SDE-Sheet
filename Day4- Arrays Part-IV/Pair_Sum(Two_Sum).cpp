#include <bits/stdc++.h> 
vector<vector<int>> pairSum(vector<int> &arr, int s)
{
    /*vector<int> ans;                //Two Sum
    unordered_map<int, int> m;
    for(int i = 0; i < arr.size(); i++)
    {
        int n = s - arr[i];
        if(m.find(n) != m.end())
        {
            ans.push_back(arr[n]);
            ans.push_back(i);
        }
        m[arr[i]] = i;
    }
    return ans;*/
    
    unordered_map<int, int> m;        //Pair Sum
    int l = arr.size();
    vector<vector<int>> ans;
    for(int i = 0; i < l; i++)
    {
        int n = m[s - arr[i]];
        while(n != 0)
        {
            ans.push_back({min(arr[i], s - arr[i]), max(arr[i], s - arr[i])});
            n--;
        }
        
        m[arr[i]] += 1;
    }
    sort(ans.begin(),ans.end());
    return ans;
   
}