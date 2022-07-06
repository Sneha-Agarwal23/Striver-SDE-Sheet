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
/*LinkedListNode<int>* reverse(LinkedListNode<int> *head)
{
    LinkedListNode<int> * prevNode = NULL;
    LinkedListNode<int> * nextNode;
    while(head != NULL)
    {
        nextNode = head->next;
        head->next = prevNode;
        prevNode = head;
        head = nextNode;
    }
    return prevNode;
}

bool isPalindrome(LinkedListNode<int> *head) 
{
    if(head == NULL)
        return true;
    LinkedListNode<int>* slow = head;
    LinkedListNode<int>* fast = head;
    LinkedListNode<int> *prev = head;
    while(fast != NULL && fast->next != NULL)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    if(fast != NULL)
    {
        slow = slow->next;
    }
    if(slow == NULL)
    {
        return true;
    }
    prev->next = NULL;
    slow = reverse(slow);
    
    while(head != NULL)
    {
        if(head->data != slow->data)
            return false;
        head = head->next;
        slow = slow->next;
    }
    return true;
}*/

bool isPalindrome(LinkedListNode<int> *head) 
{
    vector<int> arr;
    while(head != NULL)
    {
        arr.push_back(head->data);
        head = head->next;
    }
    int n = arr.size();
    for(int i = 0, j = n-1; i < n, j >= 0; i++, j--)
    {
        if(arr[i] != arr[j])
            return false;
    }
    return true;
}