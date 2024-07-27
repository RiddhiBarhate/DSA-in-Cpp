/**
 * Definition of doubly linked list:
 * class Node {
 * public:
 *      int data;
 *      Node *prev;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next, Node *prev) {
 *          this->data = data;
 *          this->prev = prev;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/

Node * removeDuplicates(Node *head)
{
   if(head == NULL){
       return head;
   }

   Node* curr = head;

   while(curr -> next != NULL){
       
       if(curr -> data == curr -> next -> data){
           Node* nodeToDelete = curr -> next;
           curr -> next = nodeToDelete -> next;
           
           if(nodeToDelete -> next != NULL){
               nodeToDelete -> next -> prev = curr;
           }
           
           delete(nodeToDelete);
       }
       else{
           curr = curr -> next;
       }
   }
   return head;

}
