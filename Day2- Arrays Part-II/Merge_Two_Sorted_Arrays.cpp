#include <bits/stdc++.h> 
vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	/*for(int i = m; i < m+n; i++)
    {
        arr1[i] = arr2[i-m];
    }
    sort(arr1.begin(), arr1.end());
    return arr1;*/
    
    vector<int> arr3;
    for(int i = 0; i < m; i++)
    {
        arr3.push_back(arr1[i]);
    }
    for(int j = 0; j < n; j++)
    {
        arr3.push_back(arr2[j]);
    }
    sort(arr3.begin(), arr3.end());
    return arr3;
}