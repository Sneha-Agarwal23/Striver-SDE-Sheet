#include<bits/stdc++.h>
void insert(stack<int>& stack, int x)
{
    if(stack.empty() || x > stack.top())
    {
        stack.push(x);
        return;
    }
    int t = stack.top();
    stack.pop();
    insert(stack, x);
    stack.push(t);
        
}
void sortStack(stack<int> &stack)
{
	if(stack.empty())
        return;
    int x = stack.top();
    stack.pop();
    sortStack(stack);
    insert(stack, x);
}