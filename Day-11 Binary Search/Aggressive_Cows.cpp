#include<bits/stdc++.h>
bool check(vector<int>& positions, int n, int c, int mid)
{
    int rooms = 1;
    int place = positions[0];
    for(int i = 1; i < n; i++)
    {
        if(positions[i] - place >= mid)
        {
            rooms++;
            place = positions[i];
        }
        if(rooms >= c)
            return true;
        
    }
    return false;
}
int chessTournament(vector<int> positions , int n ,  int c)
{
	sort(positions.begin(), positions.end());
    int ans = -1;
    int low = 1;
    int high = positions[n-1] - positions[0];
    while(low <= high)
    {
        int mid = (low + high)/2;
        if(check(positions, n, c, mid))
        {
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return ans;
}