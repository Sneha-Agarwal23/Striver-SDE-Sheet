//Coding Ninja
#include<bits/stdc++.h>
void solve(vector<vector<int> > &maze, int i, int j, vector<vector<int>>& vis, int n, vector<vector<int>>& ans)
{
    if(i < 0 || j < 0 || i >= n || j >= n|| maze[i][j] == 0 || vis[i][j] == 1)
        return;
    
    if(i == n-1 && j == n-1 && maze[i][j] == 1)
    {
        vector<int> temp;
        vis[i][j] = 1;
        for(int x = 0; x < n; x++)
        {
            for(int y = 0; y < n; y++)
            {
                temp.push_back(vis[x][y]);
            }
        }
        ans.push_back(temp);
    }
    
    vis[i][j] = 1;
    solve(maze, i+1, j, vis, n, ans);
    solve(maze, i-1, j, vis, n, ans);
    solve(maze, i, j+1, vis, n, ans);
    solve(maze, i, j-1, vis, n, ans);
    vis[i][j] = 0;
}
vector<vector<int>> ratInAMaze(vector<vector<int> > &maze, int n)
{
    vector<vector<int>> ans;
    vector<vector<int>> vis(n, vector<int>(n, 0));
    solve(maze, 0, 0, vis, n, ans);
    return ans;
}

//GFG
// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void solve(vector<vector<int>> &m, int n, int i, int j, string path, vector<vector<int>>& vis,
    vector<string>& ans)
    {
        if(i == n-1 && j == n-1)
        {
            ans.push_back(path);
            return;
        }
        
        //down
        if(i+1 < n && !vis[i+1][j] && m[i+1][j] == 1)
        {
            vis[i][j] = 1;
            solve(m, n, i+1, j, path + 'D', vis, ans);
            vis[i][j] = 0;
        }
        //left
        if(j-1 >= 0 && !vis[i][j-1] && m[i][j-1] == 1)
        {
            vis[i][j] = 1;
            solve(m, n, i, j-1, path + 'L', vis, ans);
            vis[i][j] = 0;
        }
        //right
        if(j+1 < n && !vis[i][j+1] && m[i][j+1] == 1)
        {
            vis[i][j] = 1;
            solve(m, n, i, j+1, path + 'R', vis, ans);
            vis[i][j] = 0;
        }
        //up
        if(i-1 >= 0 && !vis[i-1][j] && m[i-1][j] == 1)
        {
            vis[i][j] = 1;
            solve(m, n, i-1, j, path + 'U', vis, ans);
            vis[i][j] = 0;
        }
        
    }
    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        string path = "";
        if(m[0][0] == 1)
        {
            solve(m, n, 0, 0, path, vis, ans);
        }
        return ans;
       
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends