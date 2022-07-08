#include<bits/stdc++.h>
void permute(string s, int k, string& ans, int fact)
{
    if(k == 0)
    {
        ans.append(s);
        return;
    }
    
    ans.push_back(s[k/fact]);
    s.erase(s.begin() + k/fact);
    permute(s, k% fact, ans, fact/s.size());
}

string kthPermutation(int n, int k)
{
    string ans = "";
    string s = "";
    int fact = 1;
    for(int i = 1; i <= n; i++)
    {
        s.append(to_string(i));
        fact = fact * i;
    }
    fact = fact / n;
    permute(s, k-1, ans, fact);
    return ans;
   
}
