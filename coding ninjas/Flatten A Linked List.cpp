/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */

Node* merge(Node* down, Node* up){

	if(down == NULL)
        return up;

    if(up == NULL)
        return down;

    Node* ans = new Node(-1);
    Node* temp = ans;

    while(down != NULL && up != NULL){

        if(down -> data < up -> data){
            temp -> child = down;
            temp = down;
            down = down -> child;
        }
        else{
            temp -> child = up;
            temp = up;
            up = up -> child;
        }
    }

    while(down != NULL){
        temp -> child = down;
        temp = down;
        down = down -> child;
    }

    while(up != NULL){
        temp -> child = up;
        temp = up;
        up = up -> child;
    }

    Node* result = ans -> child;
    return result;
}

Node* flattenLinkedList(Node* head) 
{
	if(head == NULL || head -> next == NULL)
		return head;

	Node* down = head;
	Node* right = head -> next;

	Node* up = flattenLinkedList(right);
	down -> next = NULL;

	Node* result = merge(down, up);

	return result;
}
