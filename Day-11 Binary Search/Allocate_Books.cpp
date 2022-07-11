#include<bits/stdc++.h>
bool check(int n, int m, vector<int>& time, long long int mid)
{
    int day = 1;
    long long reqtime = 0;
    for(int i = 0; i < m; i++)
    {
        if(reqtime + time[i] <= mid)
            reqtime += time[i];
        else
        {
            day++;
            if(day > n || time[i] > mid)
            {
                return false;
            }
            reqtime = time[i];
                
        }
    }
    return true;
}
long long ayushGivesNinjatest(int n, int m, vector<int> time) 
{	
	long long totaltime= 0;
    for(int i = 0; i < time.size(); i++)
    {
        totaltime = totaltime + time[i];
    }
    long long low = 0;
    long long high = totaltime;
    long long ans = -1;
    while(low <= high)
    {
        long long mid = (low + high)/2;
        if(check(n, m, time, mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}