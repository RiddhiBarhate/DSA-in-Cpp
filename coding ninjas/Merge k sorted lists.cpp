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

Node* mergeKLists(vector<Node*> &listArray){
    int k = listArray.size();
    Node *head = new Node(-1);
    Node *temp = head;
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i = 0; i < k; i++){
        Node *temp1 = listArray[i];
        while(temp1 != NULL){
            pq.push(temp1 -> data);
            temp1 = temp1 -> next;
        }
    }

    while(!pq.empty()){
        Node *top = new Node(pq.top());
        pq.pop();

        head -> next = top;
        head = head -> next;
    }

    return temp -> next;
}