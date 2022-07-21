int convert(char c)
{
    if(c == 'I') return 1;
    else if(c == 'V') return 5;
    else if(c == 'X') return 10;
    else if(c == 'L') return 50;
    else if(c == 'C') return 100;
    else if(c == 'D') return 500;
    else if(c == 'M') return 1000;
    
}

int romanToInt(string s) 
{
    int n = s.size();
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        int current = convert(s[i]);
        int next = 0;
        if(i <= n-1)
        {
            next = convert(s[i+1]);
        }
        if(current < next)
        {
            ans = ans + (next - current);
            i++;
        }
        else
            ans = ans + current;
    }
    return ans;
    
}
