vector<int> stringMatch(string &str, string &pat) 
{
    vector<int> ans;
    int n = str.size();
    int m = pat.size();
    int i = 0;
    while((i+m-1) < n)
    {
        string s = str.substr(i, m);
        if(s == pat)
            ans.push_back(i);
        i++;
    }
    return ans;
    
}
