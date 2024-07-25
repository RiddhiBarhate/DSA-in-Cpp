/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node* kReverse(Node* head, int k) {
    //base case
    if(head == NULL){
        return NULL;
    }

    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;
    int cnt = 0;

    // Check the length of the remaining part of the list
    Node* check = head;
    int remainingLength = 0;
    while (check != NULL && remainingLength < k) {
        check = check->next;
        remainingLength++;
    }

    // If remaining length is less than k, return head without reversing
    if (remainingLength < k) {
        return head;
    }

    //Step 1 - Reverse the k list
    while(curr != NULL && cnt < k){
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
        cnt++;
    }

    //Step 2 - Recursive call
    if (next != NULL) {
        head->next = kReverse(next, k);
    }
    
   
    //Step 3 - Return head of reversed list
    return prev;

}