#include<bits/stdc++.h>
class Queue {
    // Define the data members(if any) here.
    
    public:
    stack<int> s1;
    stack<int> s2;
    Queue() {
        // Initialize your data structure here.
    }

    void enQueue(int val) 
    {
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(val);
        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
      
    }

    int deQueue() 
    {
        if(isEmpty())
            return -1;
        int x = s1.top();
        s1.pop();
        return x;
       
    }

    int peek() 
    {
        if(isEmpty())
            return -1;
        return s1.top();
       
    }

    bool isEmpty()
    {
        return s1.empty(); 
    }
};