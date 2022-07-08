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

Node *addTwoNumbers(Node *head1, Node *head2)
{
    Node* p = new Node(1);
    Node* temp = p;
    int carry = 0;
    while(head1 != NULL || head2 != NULL || carry != NULL)
    {
        int sum = 0;
        if(head1 != NULL)
        {
            sum = sum + head1->data;
            head1 = head1->next;
        }
        if(head2 != NULL)
        {
            sum = sum + head2->data;
            head2 = head2->next;
        }
        sum = sum + carry;
        carry = sum/10;
        Node* q = new Node(sum % 10);
        temp->next = q;
        temp = temp->next;
    }
    return p->next;
}