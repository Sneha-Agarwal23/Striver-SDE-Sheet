//Coding Ninja
#include<bits/stdc++.h>
bool check(int matrix[9][9], int i, int j, int x)
{
    int row = i - i%3;
    int col = j - j%3;
    for(int r = 0; r < 9; r++)
    {
        if(matrix[r][j] == x)
            return false;
    }
    for(int c = 0; c < 9; c++)
    {
        if(matrix[i][c] == x)
            return false;
    }
    for(int r = 0; r < 3; r++)
    {
        for(int c = 0; c < 3; c++)
        {
            if(matrix[r + row][c + col] == x)
                return false;
        }
    }
    return true;
}
bool solve(int matrix[9][9], int i, int j)
{
    if(i == 9)
        return true;
    if(j == 9)
        return solve(matrix, i+1, 0);
    if(matrix[i][j] != 0)
        return solve(matrix, i, j+1);
    
    for(int x = 1; x <= 9; x++)
    {
        if(check(matrix, i, j, x))
        {
            matrix[i][j] = x;
            if(solve(matrix, i, j+1))
                return true;
            matrix[i][j] = 0;
        }
    }
    return false;
}
bool isItSudoku(int matrix[9][9])
{
    solve(matrix, 0, 0);
}


//Leetcode
class Solution {
public:
    bool solve(vector<vector<char>>& board, int i, int j)
    {
        if(i == 9)
            return true;
        if(j == 9)
            return solve(board, i+1, 0);
        if(board[i][j] != '.')
            return solve(board, i, j+1);
        for(char c = '1'; c <= '9'; c++)
        {
            if(check(board, i, j, c) == true)
            {
                board[i][j] = c;
                if(solve(board, i, j+1) == true)
                    return true;
                board[i][j] = '.';
            }
        }
        return false;
    }
    
    bool check(vector<vector<char>>& board, int i, int j, char value)
    {
        int row = i - i%3;
        int col = j - j%3;
        for(int x = 0; x < 9; x++)
        {
            if(board[x][j] == value)
                return false;
        }
        for(int y = 0; y < 9; y++)
        {
            if(board[i][y] == value)
                return false;
        }
        for(int x = 0; x < 3; x++)
        {
            for(int y = 0; y < 3; y++)
            {
                if(board[x+row][y+col] == value)
                    return false;
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board)
    {
        solve(board, 0, 0);
        
    }
};