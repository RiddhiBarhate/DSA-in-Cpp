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

void insertAtTail(Node* &tail, Node* curr){
    tail -> next = curr;
    tail = curr;
}

Node* sortList(Node *head){

    //Approach 1 - Replace data
    /*int cntZero = 0;
    int cntOne = 0;
    int cntTwo = 0;

    Node* curr = head;

    while(curr != NULL){
        if(curr -> data == 0){
            cntZero++;
        }
        else if(curr -> data == 1){
            cntOne++;
        } 
        else{
            cntTwo++;
        }   
        curr = curr -> next;
    }

    curr = head;

    while(cntZero > 0 && curr != NULL){
        curr -> data = 0;
        cntZero--;
        curr = curr -> next;
    }

    while(cntOne > 0 && curr != NULL){
        curr -> data = 1;
        cntOne--;
        curr = curr -> next;
    }

    while(cntTwo > 0 && curr != NULL){
        curr -> data = 2;
        cntTwo--;
        curr = curr -> next;
    }

    return head;*/

    //Approach 2 - change pointers
    Node* zerohead = new Node(-1);
    Node* zerotail = zerohead;
    Node* onehead = new Node(-1);
    Node* onetail = onehead;
    Node* twohead = new Node(-1);
    Node* twotail = twohead;

    Node* curr = head;

    while(curr != NULL){
        int value = curr -> data;
        if(value == 0){
            insertAtTail(zerotail, curr);
        }
        else if(value == 1){
            insertAtTail(onetail, curr);
        }
        else{
            insertAtTail(twotail, curr);
        }
        curr = curr -> next;
    }

    //merge 3 list

    if(onehead -> next != NULL){        //1's list is non-empty
        zerotail -> next = onehead -> next;
    }
    else{
        //1's list is empty
        zerotail -> next = twohead -> next;   
    }
    onetail -> next = twohead -> next;
    twotail -> next = NULL;

    //set head
    head = zerohead -> next;

    //delete dummy nodes
    delete zerohead;
    delete onehead;
    delete twohead;

    return head;
}