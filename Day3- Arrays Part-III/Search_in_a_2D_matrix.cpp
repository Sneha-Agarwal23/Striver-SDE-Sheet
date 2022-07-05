#include <bits/stdc++.h> 
#include <vector>

bool findTargetInMatrix(vector < vector < int >> & mat, int m, int n, int target) {
    /*for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(mat[i][j] == target)
                return true;
        }
    }
    return false;*/
    
    int i = 0;
    int j = n-1;
    while(i < m && j >= 0)
    {
        int x = mat[i][j];
        if(x == target)
            return true;
        else if(x < target)
            i++;
        else
            j--;
    }
    return false;
    
}