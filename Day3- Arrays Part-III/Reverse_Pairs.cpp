class Solution {
public:
    int merge(vector<int>& a, int left, int mid, int right)
{
    int i, j;
    i = left;
    j = mid+1;
    int count = 0;
        
    for(int i = left; i<=mid; i++)
    {
        while(j<=right && a[i] > 2LL*a[j])
            j++;
        count = count + (j - mid-1);
    }
    i = left;
    j = mid+1;
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

    return count;
}

int mergeSort(vector<int>& a, int left, int right)
{
    if(left >= right)
        return 0;
    int mid = (left+right)/2;
    int count = 0;
    count = count + mergeSort(a, left, mid);
    count = count + mergeSort(a, mid+1, right);
    count = count + merge(a, left, mid, right);
    return count;

}
    int reversePairs(vector<int>& a) 
    {
         return mergeSort(a, 0, a.size() - 1);
        
    }
};