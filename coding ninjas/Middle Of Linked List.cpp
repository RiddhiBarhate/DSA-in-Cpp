/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/

int getlen(Node* &head){
    int len = 0;
    Node* temp = head;
    while(temp != NULL){
        temp = temp -> next;
        len++;
    }
    return len;
}

Node *findMiddle(Node *head) {
    
    //Approach 1
    /*int len = getlen(head);
    int ans = len/2;
    int cnt = 0;
    Node* temp = head;

    while(cnt < ans){
        temp = temp -> next;
        cnt++;
    }
    return temp;*/

    //Approach 2
    if(head == NULL || head -> next == NULL){
        return head;
    }

    Node* fast = head -> next;
    Node* slow = head;

    while(fast != NULL){
        fast = fast -> next;
        if(fast != NULL){
            fast = fast -> next;
        }

        slow = slow -> next;
    }
    return slow;
}

