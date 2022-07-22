#include<bits/stdc++.h>
int minTimeToRot(vector<vector<int>>& grid, int n, int m)
{
    int count = 0;
    int result = -1;
    queue<vector<int>> q;
    vector<vector<int>> dir = {{-1,0} , {1,0}, {0,-1}, {0,1}};
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(grid[i][j] > 0)
                count++;
            if(grid[i][j] == 2)
                q.push({i,j});
        }
    }
    
    while(!q.empty())
    {
        result++;
        int s = q.size();
        for(int i = 0; i < s; i++)
        {
            vector<int> v = q.front();
            count--;
            q.pop();
            for(int j = 0; j < 4; j++)
            {
                int x = v[0] + dir[j][0];
                int y = v[1] + dir[j][1];
                if(x >= n || y >= m || x < 0 || y < 0 || grid[x][y] != 1)
                    continue;
                grid[x][y] = 2;
                q.push({x,y});
            }
        }   
    }
    if(count == 0)
        return max(0, result);
    return -1;

}