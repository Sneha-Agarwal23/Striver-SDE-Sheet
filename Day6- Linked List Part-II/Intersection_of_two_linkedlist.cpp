#include <bits/stdc++.h> 
/****************************************************************
 
    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

int findIntersection(Node *firstHead, Node *secondHead)
{
    /*Node * p = firstHead;
    Node * q = secondHead;
    while(p != q)
    {
        if(p == NULL)
            p = secondHead;
        else
            p = p->next;
        if(q == NULL)
            q = firstHead;
        else
            q = q->next; 
    }
    return p->data;*/
    
    unordered_map<Node*, int> m;
    while(firstHead != NULL)
    {
        m[firstHead]++;
        firstHead = firstHead->next;
    }
    while(secondHead != NULL)
    {
        if(m[secondHead] > 0)
            return secondHead->data;
        secondHead = secondHead->next;
    }
    return -1;
}