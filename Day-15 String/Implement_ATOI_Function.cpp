#include<bits/stdc++.h>
int atoi(string str)
{
    int ans = 0;
    int n = str.length();
    bool neg = false;
    for(int i = 0; i < n; i++)
    {
        if(str[i] >= '0' && str[i] <= '9')
        {
            int d = str[i] - 48;
            ans = ans * 10 + d;
        }
    }
    if(str[0] == '-')
        neg = true;
    if(neg == true)
        ans = ans * (-1);
    return ans;
    
}