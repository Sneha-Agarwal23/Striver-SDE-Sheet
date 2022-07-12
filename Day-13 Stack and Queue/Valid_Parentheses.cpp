#include<bits/stdc++.h>
bool isValidParenthesis(string e)
{
    stack<char> s;
    for(int i = 0; i < e.size(); i++)
    {
        if(e[i] == '(' || e[i] == '{' || e[i] == '[')
        {
            s.push(e[i]);
            continue;
        }
        else
        {
            if(s.empty())
                return false;
            else if(e[i] == ')' && s.top() != '(')
                return false;
            else if(e[i] == '}' && s.top() != '{')
                return false;
            else if(e[i] == ']' && s.top() != '[')
                return false;
            s.pop();
            
        }
    }
    return s.empty();
}