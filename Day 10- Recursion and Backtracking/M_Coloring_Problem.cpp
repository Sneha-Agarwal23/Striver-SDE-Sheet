#include<bits/stdc++.h>
bool check(vector<vector<int>> &mat, vector<int>& color, int node, int x, int n)
{
    for(int i = 0; i < n; i++)
    {
        if(node != i && mat[node][i] == 1 && color[i] == x)
            return false;
    }
    return true;
}
bool solve(vector<vector<int>> &mat, vector<int>& color, int n, int m, int node)
{
    if(node == n)
        return true;
    
    for(int i = 1; i <= m; i++)
    {
        if(check(mat, color, node, i, n))
        {
            color[node] = i;
            if(solve(mat, color, n, m, node+1))
                return true;
            color[node] = 0;
        }
    }
    return false;
}

string graphColoring(vector<vector<int>> &mat, int m)
{
    int n = mat.size();
    vector<int> color(n, 0);
    if(solve(mat, color, n, m, 0))
        return "YES";
    return "NO";
    
}