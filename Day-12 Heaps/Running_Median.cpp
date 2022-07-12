#include<bits/stdc++.h>
void findMedian(int *arr, int n)
{
    if(n == 0)
        return;
    
    priority_queue<int, vector<int>, greater<int>> minheap;
    priority_queue<int> maxheap;
    
    maxheap.push(arr[0]);
    cout<<arr[0]<<" ";
    
    for(int i = 1; i < n; i++)
    {
        int x = arr[i];
        if(maxheap.size() > minheap.size())
        {
            if(maxheap.top() > x)
            {
                minheap.push(maxheap.top());
                maxheap.pop();
                maxheap.push(x);
            }
            else
            {
                minheap.push(x);
            }
            cout<<(((int)maxheap.top() + minheap.top())/2)<<" ";
        }
        else
        {
            if(x <= maxheap.top())
                maxheap.push(x);
            else
            {
                minheap.push(x);
                maxheap.push(minheap.top());
                minheap.pop();
            }
            cout<<maxheap.top()<<" ";
        }
    }
}