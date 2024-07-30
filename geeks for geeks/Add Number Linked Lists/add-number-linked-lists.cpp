//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    if (arr.empty()) {
        return NULL;
    }
    int val = arr[0];
    int size = arr.size();

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 1; i < size; i++) {
        val = arr[i];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {

  private:
  
    Node* reverse(struct Node* head){
        
        Node* curr = head;
        Node* next = NULL;
        Node* prev = NULL;
        
        while(curr != NULL){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }
    
    Node* add(struct Node* num1, struct Node* num2){
        
        Node* anshead = NULL;
        Node* anstail = NULL;
        int carry = 0;
        
        while(num1 != NULL || num2 != NULL || carry != 0){
            
            int val1 = 0;
            if(num1 != NULL)
                val1 = num1 -> data;
            
            int val2 = 0;
            if(num2 != NULL)
                val2 = num2 -> data;
                
            int sum = carry + val1 + val2;
            int digit = sum % 10;
            carry = sum / 10;
            
            insertAtTail(anshead, anstail, digit);
            
            if(num1 != NULL)
                num1 = num1 -> next;
                
            if(num2 != NULL)
                num2 = num2 -> next;
        }
        return anshead;
    }
    
    void insertAtTail(struct Node* &head, struct Node* &tail, int value){
        
        Node* temp = new Node(value);
        
        if(head == NULL){
            head = temp;
            tail = temp;
            return;
        }
        else{
            tail -> next = temp;
            tail = temp;
        }
    }
    
    Node* removeLeadingZero(Node* head){
        
        while(head -> data == 0){
            
            if(head != NULL && head -> data == 0){
                Node* temp = head;
                head = head -> next;
                delete temp;
            }
        }
        
        if(head == NULL){
            return new Node(0);
        }
        
        return head;
    }
  
  public:
    // Function to add two numbers represented by linked list.
    Node* addTwoLists(struct Node* num1, struct Node* num2) {
        
        //Step 1 - Reverse the input LL
        num1 = reverse(num1);
        num2 = reverse(num2);
        
        //Step 2 - Add both the LL
        Node* ans = add(num1, num2);
        
        //Step 3 - Reverse the ans ll
        ans = reverse(ans);
        
        ans = removeLeadingZero(ans);
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while (t--) {
        Node* num1 = buildList();
        Node* num2 = buildList();
        Solution ob;
        Node* res = ob.addTwoLists(num1, num2);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends