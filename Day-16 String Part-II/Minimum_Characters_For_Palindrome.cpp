#include<bits/stdc++.h>
bool check(string& s, int start, int end)
{
    while(start < end)
    {
        if(s[start] != s[end])
            return false;
        start++;
        end--;
    }
    return true;
}
int minCharsforPalindrome(string str) 
{
    int n = str.size();
    int i = 0, j = n-1;
    while(j > 0)
    {
        if(check(str, 0, j))
            return n-j-1;
        else
            j--;
    }
    return n-1;
}
