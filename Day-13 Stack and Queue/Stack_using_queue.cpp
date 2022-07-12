#include<bits/stdc++.h>
class Stack {
	// Define the data members.

   public:
    queue<int> q1;
    queue<int> q2;
    Stack() {
        
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize() 
    {
        return q1.size();
        
    }

    bool isEmpty() {
        if(getSize() == 0)
            return true;
        else
            return false;
    }

    void push(int element)
    {
        q2.push(element);
        while(q1.size() > 0)
        {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
        
    }

    int pop() 
    {
        if(isEmpty())
            return -1;
        int x = q1.front();
        q1.pop();
        return x;
        
    }

    int top() 
    {
        if(isEmpty())
            return -1;
        int x = q1.front();
        return x;
        
    }
};