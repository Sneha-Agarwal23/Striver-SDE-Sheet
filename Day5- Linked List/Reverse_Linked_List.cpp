#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    LinkedListNode<int> *prevnode = NULL;
    LinkedListNode<int> *nextnode;
    while(head != NULL)
    {
        nextnode = head->next;
        head->next = prevnode;
        prevnode = head;
        head = nextnode;
    }
    return prevnode;
   
}