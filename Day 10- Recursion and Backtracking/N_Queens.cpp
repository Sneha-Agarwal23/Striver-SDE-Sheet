//Coding Ninja
#include<bits/stdc++.h>
bool check(vector<vector<int>>& board, int row, int col)
{
    int n = board.size();
    for(int i = 0; i < row; i++)
    {
        if(board[i][col] == 1)
            return false;
    }
    for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if(board[i][j] == 1)
            return false;
    }
    for(int i = row - 1,  j = col + 1; i >= 0 && j < n; i--,j++)
    {
        if(board[i][j] == 1)
            return false;
    }
    return true;
}
void solve(vector<vector<int>>& ans, vector<vector<int>>& board, int row)
{
    if(row >= board.size())
    {
        vector<int> temp;
        for(auto i : board)
        {
            for(auto j : i)
            {
                temp.push_back(j);
            }
        }
        ans.push_back(temp);
        return;
    }
    
    for(int col = 0; col < board.size(); col++)
    {
        if(check(board, row, col))
        {
            board[row][col] = 1;
            solve(ans, board, row+1);
            board[row][col] = 0;
        }
    }
    
}
    
vector<vector<int>> solveNQueens(int n)
{
    vector<vector<int>> ans;
    vector<vector<int>> board(n, vector<int>(n, 0));
    solve(ans, board, 0);
    return ans; 
}

//Leetcode
class Solution {
public:
    bool check(vector<string>& board, int row, int col)
    {
        int n = board.size();
        for(int i = 0; i < n; i++)
        {
            if(board[i][col] == 'Q')
                return false;
            if(row - i >= 0 && col - i >= 0 && board[row-i][col-i] == 'Q')
                return false;
            if(row - i >= 0 && col + i < n && board[row-i][col+i] == 'Q')
                return false;
            if(row + i < n && col - i >= 0 && board[row+i][col-i] == 'Q')
                return false;
            if(row + i < n && col + i < n && board[row+i][col+i] == 'Q')
                return false;
        }
        return true;
    }
    void solve(vector<string>& board, vector<vector<string>>& ans, int row)
    {
        if(row == board.size())
        {
            ans.push_back(board);
            return;
        }
        
        for(int col = 0; col < board.size(); col++)
        {
            if(check(board, row, col))
            {
                board[row][col] = 'Q';
                solve(board, ans, row+1);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        solve(board, ans, 0);
        return ans;
        
    }
};