#include<bits/stdc++.h>

void solve(string& s, int index, vector<string>& dictionary, vector<string>& ans, string& v)
{
    if(index >= s.size())
    {
        ans.push_back(v);
        return;
    }
    
    for(int i = index; i < s.size(); i++)
    {
        string temp = s.substr(index, i - index + 1);
        bool flag = false;
        for(string st : dictionary)
        {
            if(st.compare(temp) == 0)
            {
                flag = true;
                break;
            }
        }
        if(flag == true)
        {
            string x = v;
            v = v + temp + " ";
            solve(s, i+1, dictionary, ans, v);
            v = x;
        }
    }
}
vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    vector<string> ans;
    string v;
    solve(s, 0, dictionary, ans, v);
    return ans;
}