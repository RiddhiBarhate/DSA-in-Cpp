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

Node *removeDuplicates(Node *head)
{
    if(head == NULL)
        return head;
        
    unordered_map<int, bool> visited;
    Node* curr = head;
    Node* prev = NULL;

    while(curr != NULL){
        if(visited[curr -> data] == true){
            //Duplicate present
            curr = curr -> next;
            delete(prev -> next);
            prev -> next = curr;
        }
        else{
            visited[curr -> data] = true;
            prev = curr;
            curr = curr -> next;
        }
        
    }
    return head;

}