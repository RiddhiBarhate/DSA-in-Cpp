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

void reverse(LinkedListNode<int>* &head, LinkedListNode<int>* prev, LinkedListNode<int>* curr){
    //base case
    if(curr == NULL){
        head = prev;
        return;
    }

    LinkedListNode<int>* forward = curr -> next;
    reverse(head, curr, forward);
    curr -> next = prev;

}

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    //Approach 2 - Recursive solution
    LinkedListNode<int>* prev = NULL;
    LinkedListNode<int>* curr = head;
    reverse(head, prev, curr);
    return head;


    //Approach 1 - Iterative approach
   /*if(head == NULL || head -> next == NULL){
       return head;
   }

   LinkedListNode<int>* prev = NULL;
   LinkedListNode<int>* curr = head;
   LinkedListNode<int>* forward = NULL;

   while(curr != NULL){
       forward = curr -> next;
       curr -> next = prev;
       prev = curr;
       curr = forward;
   }
   return prev;*/
}