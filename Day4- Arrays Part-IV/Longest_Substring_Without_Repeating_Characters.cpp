#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    unordered_set<char> s;
    int n = input.size();
    int i = 0, j = 0, result = 0;
    while(i < n && j < n)
    {
        if(s.find(input[i]) == s.end())
        {
            s.insert(input[i]);
            i++;
            result = max(result, i-j);
        }
        else
        {
            s.erase(input[j]);
            j++;
        }
    }
    return result;
}