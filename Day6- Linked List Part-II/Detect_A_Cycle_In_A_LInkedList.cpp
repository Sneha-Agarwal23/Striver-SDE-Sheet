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

bool detectCycle(Node *head)
{
	/*Node* slow = head;
    Node* fast = head;
    if(head == NULL)
        return NULL;
    while(fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            return true;
    }
    return false;*/
    
    unordered_set<Node*> s;
    while(head != NULL)
    {
        if(s.find(head) != s.end())
            return true;
        else
        {
            s.insert(head);
            head = head->next;
        }
    }
    return false;
}