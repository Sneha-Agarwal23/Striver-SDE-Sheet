#include<bits/stdc++.h> 
int largestRectangle(vector < int > & heights)
{
    int n = heights.size();
    int maxarea = 0;
    int h, b;
    stack<int> indexes;
    for(int i = 0; i <= n; i++)
    {
        while(i == n || !indexes.empty() && heights[indexes.top()] >= heights[i])
        {
            if(i == n && indexes.empty())
            {
                h = 0;
                i++;
            }
            else
            {
                h = heights[indexes.top()];
                indexes.pop();
            }
            if(indexes.empty())
                b = -1;
            else
                b = indexes.top();
            int area = h * (i - b - 1);
            maxarea = max(area, maxarea);
        }
        indexes.push(i);
    }
    return maxarea;
   
}