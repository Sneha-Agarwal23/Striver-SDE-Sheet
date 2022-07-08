#include<bits/stdc++.h>
bool ispalindrome(string& s, int start, int end)
{
    while(start <= end)
    {
        if(s[start] != s[end])
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

void substring(string &s,vector<vector<string>>& ans, vector<string>& v, int index)
{
    if(index == s.size())
    {
        ans.push_back(v);
        return;
    }
    for(int i = index; i < s.size(); i++)
    {
        if(ispalindrome(s, index, i))
        {
            v.push_back(s.substr(index, i - index + 1));
            substring(s, ans, v, i+1);
            v.pop_back();
        }
    }
}
vector<vector<string>> partition(string &s) 
{
    vector<vector<string>> ans;
    vector<string> v;
    substring(s, ans, v, 0);
    return ans;
    
}