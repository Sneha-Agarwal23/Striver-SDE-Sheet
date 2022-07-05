#include <bits/stdc++.h> 
int count(int m, int n, vector<vector<int>>& dp)
{
    if(m == 0 || n == 0)
        return 0;
    if(m == 1 || n == 1)
        return 1;
    if(dp[m][n] != -1)
        return dp[m][n];
    return dp[m][n] = count(m, n-1, dp) + count(m-1, n, dp);
}
int uniquePaths(int m, int n) {
	vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
    return count(m , n, dp);
    
}