#include <bits/stdc++.h> 
/*************************************************************

    Following is the LinkedListNode class structure

    template <typename T>   
    class LinkedListNode
    {
        public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode<T> *random;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*************************************************************/

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    unordered_map<LinkedListNode<int>*, LinkedListNode<int>*> m;
    LinkedListNode<int>* org = head;
    LinkedListNode<int>* copy = NULL;
    while(org != NULL)
    {
        copy = new LinkedListNode<int>(org->data);
        m.insert({org, copy});
        org = org->next;
    }
    org = head;
    while(org != NULL)
    {
        copy = m[org];
        copy->next = m[org->next];
        copy->random = m[org->random];
        org = org->next;
    }
    return m[head];
}
