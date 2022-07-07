#include<bits/stdc++.h>
int removeDuplicates(vector<int> &arr, int n) 
{
    set<int> s;
    for(int i = 0; i < arr.size(); i++)
    {
        s.insert(arr[i]);
    }
    return s.size();

/*int i = 0;
    for(int j = 1; j < n; j++)
    {
        if(arr[j] != arr[j-1])
        {
            arr[i] = arr[j];
            i++;
        }
    }
    return i+1;*/
}