#include<bits/stdc++.h>
// Implement class for minStack.
class minStack
{
	// Write your code here.
	
	public:
		stack<int> s;
        stack<int> m;
		// Constructor
		minStack() 
		{ 
			// Write your code here.
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int num)
		{
			s.push(num);
            if(m.empty() || m.top() >= num)
            {
                m.push(num);
            }
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
			if(!m.empty() && m.top() == s.top())
            {
                m.pop();
            }
            int x = -1;
            if(!s.empty())
            {
                x = s.top();
                s.pop();
            }
            return x;
		}
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
			int x = -1;
            if(!s.empty())
                x = s.top();
            return x;
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
            int x = -1;
			if(!m.empty())
            {
                x = m.top();
            }
            return x;
		}
};