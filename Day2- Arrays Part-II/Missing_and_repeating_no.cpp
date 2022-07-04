#include <bits/stdc++.h> 

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
    int missing = 0;
    int repeating = 0;
	unordered_map<int, int> m;
    for(int i = 0; i < n; i++)
    {
        m[arr[i]]++;
    }
    for(int i = 1; i <= n; i++)
    {
        if(m[i] > 1)
            repeating = i;
        
        if(m[i] == 0)
            missing = i;
    }
    return {missing, repeating};
    
	
}
