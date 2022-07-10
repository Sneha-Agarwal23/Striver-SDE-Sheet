#include<bits/stdc++.h>
/*void swap(string &s, int i, int j)
{
    char temp = s[i];
    s[i] = s[j];
    s[j] = temp;
}
void permute(string &s, vector<string>& ans, int i, int l)
{
    if(i >= l)
    {
        string p = "";
        for(int j = 0; j < s.size(); j++)
        {
            p = p + s[j];
        }
        ans.push_back(p);
        return;
    }
    
    for(int j = i; j <= l; j++)
    {
        swap(s, i, j);
        permute(s, ans, i+1, l);
        swap(s, i, j);
    }
}
vector<string> findPermutations(string &s) 
{
    vector<string> ans;
    int l = s.size() - 1;
    permute(s, ans, 0, l);
    return ans;
}*/
void permute(string& s, vector<string>& ans, int index)
{
    if(index == s.size())
    {
        ans.push_back(s);
        return;
    }
    
    for(int i = index; i < s.size(); i++)
    {
        swap(s[index], s[i]);
        permute(s, ans, index+1);
        swap(s[index], s[i]);
    }
}
vector<string> findPermutations(string &s) 
{
    vector<string> ans;
    permute(s, ans, 0);
    return ans;
    
}