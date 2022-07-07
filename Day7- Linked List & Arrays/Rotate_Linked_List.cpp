#include <bits/stdc++.h> 
/********************************

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

********************************/


Node *rotate(Node *head, int k) 
{
    if(head == NULL)
        return head;
    Node* temp = head;
    int length = 1;
    while(temp->next != NULL)
    {
        length++;
        temp = temp->next;
    }
    if(length < k)
    {
        k = k % length;
    }
    if(length - k == 0 || length - k == length)
        return head;
    
    Node* curr = head;
    for(int i = 1; i < length - k; i++)
    {
        curr = curr->next;
    }
    if(curr == NULL)
        return head;
    temp->next = head;
    head = curr->next;
    curr->next = NULL;
    return head;
}