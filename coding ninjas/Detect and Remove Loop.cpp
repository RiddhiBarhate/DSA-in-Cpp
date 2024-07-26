/*************************************************
    
    class Node {
        public :

        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
    };

*************************************************/

Node* FloydCycle(Node* head){
	if(head == NULL)
		return NULL;

	Node* slow = head;
	Node* fast = head;

	while(slow != NULL && fast != NULL){

		fast = fast -> next;
		if(fast != NULL){
			fast = fast -> next;
		}

		slow = slow -> next;

		if(fast == slow){
			return slow;
		}
	}
	return NULL;
}

Node* getStartNode(Node* head){
	if(head == NULL)
		return NULL;

	Node* intersection = FloydCycle(head);
    if(intersection == NULL){
        return NULL;
    }

	Node* slow = head;

	while(slow != intersection){
		slow = slow -> next;
		intersection = intersection -> next;
	}

	return slow;
}

Node *removeLoop(Node *head)
{
    if(head == NULL)
		return head;

	Node* startOfNode = getStartNode(head);
    if(startOfNode == NULL){
        return head;
    }

	Node* temp = startOfNode;

	while(temp -> next != startOfNode){
		temp = temp -> next;
	}

	temp -> next = NULL;
    return head;
}