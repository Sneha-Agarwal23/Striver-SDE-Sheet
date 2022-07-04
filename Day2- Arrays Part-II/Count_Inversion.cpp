#include<bits/stdc++.h>
using namespace std;

int merge(vector<int>& a, int left, int mid, int right)
{
    int i, j;
    i = left;
    j = mid+1;
    int inv = 0;
    vector<int> temp;
    while(i <= mid && j <= right)
    {
        if(a[i] <= a[j])
        {
            temp.push_back(a[i]);
            i++;
        }
        else
        {
            temp.push_back(a[j]);
            j++;
            inv = inv + (mid - i + 1);
        }
    }
    while(i <= mid)
    {
        temp.push_back(a[i]);
        i++;
    }
    while(j <= right)
    {
        temp.push_back(a[j]);
        j++;
    }
    for(int i = left; i <= right; i++)
    {
        a[i] = temp[i - left];
    }

    return inv;
}

int mergeSort(vector<int>& a, int left, int right)
{
    if(left >= right)
        return 0;
    int mid = (left+right)/2;
    int inv = 0;
    inv = inv + mergeSort(a, left, mid);
    inv = inv + mergeSort(a, mid+1, right);
    inv = inv + merge(a, left, mid, right);
    return inv;

}

void app(vector<int>& a)		//Brute Force - TLE
{
    int n = a.size();
    int count = 0;
    for(int i = 0; i < n-1; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(a[i] > a[j])
                count++;
        }
    }
    cout<<"No of inversions: "<<count<<endl;
}

int main()
{
    vector<int> a;
    a.push_back(2);
    a.push_back(1);
    a.push_back(3);
    a.push_back(1);
    a.push_back(2);
    app(a);	
    int inv = mergeSort(a, 0, a.size() - 1);
    for(auto i : a)
    {
        cout<<i<<" ";
    }
    cout<<"Number of inversion are : "<<inv<<endl;

    return 0;

}
