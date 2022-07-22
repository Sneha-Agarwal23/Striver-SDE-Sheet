bool findPattern(string p, string s)
{
    if(s.size() != 0 && s.find(p) <= s.size())
        return true;
    return false;
        
}