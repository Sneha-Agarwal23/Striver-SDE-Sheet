#include <bits/stdc++.h> 
int modularExponentiation(int x, int n, int m) 
{
    long long ans = 1;
    long a = x;
    while(n > 0)
    {
        if(n%2 == 0)
        {
            a = a%m * a%m;
            n = n/2;
        }
        else
        {
            ans = ans * a%m;
            n = n-1;
        }
    }
    return ans;
	
}