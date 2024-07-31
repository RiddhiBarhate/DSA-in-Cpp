//{ Driver Code Starts
#include <bits/stdc++.h>

#include <iostream>
#include <map>
#include <sstream>
#include <vector>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    Node *next;
    Node *arb;

    Node(int x) {
        data = x;
        next = NULL;
        arb = NULL;
    }
};

void print(Node *root) {
    Node *temp = root;
    while (temp != NULL) {
        int k;
        if (temp->arb == NULL)
            k = -1;
        else
            k = temp->arb->data;
        cout << temp->data << " " << k << " ";
        temp = temp->next;
    }
}

void append(Node **head_ref, Node **tail_ref, int new_data) {
    Node *new_node = new Node(new_data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
    } else {
        (*tail_ref)->next = new_node;
    }
    *tail_ref = new_node;
}

bool validation(Node *head, Node *res) {
    Node *temp1 = head;
    Node *temp2 = res;

    while (temp1 != NULL && temp2 != NULL) {
        if (temp1->data != temp2->data)
            return false;
        if ((temp1->arb == NULL && temp2->arb != NULL) ||
            (temp1->arb != NULL && temp2->arb == NULL) ||
            (temp1->arb != NULL && temp2->arb != NULL &&
             temp1->arb->data != temp2->arb->data))
            return false;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return true;
}


// } Driver Code Ends
/* Link list Node
struct Node {
    int data;
    Node *next;
    Node *arb;

    Node(int x) {
        data = x;
        next = NULL;
        arb = NULL;
    }
};*/

class Solution {
  
  private:
  
  void insertAtTail(Node* &head, Node* &tail, int d){
      Node* newNode = new Node(d);
      
      if(head == NULL){
          head = newNode;
          tail = newNode;
          return;
      }
      else{
          tail -> next = newNode;
          tail = newNode;
      }
  }
  
  public:
    Node *copyList(Node *head) {
        
        //Approach 1
        
        //Step 1 - Clone the LL using next pointer
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        
        Node* temp = head;
        while(temp != NULL){
            
            insertAtTail(cloneHead, cloneTail, temp -> data);
            temp = temp -> next;
        }
        
        //Step 2 - Create a mapping
        unordered_map<Node* ,Node*> OldToNewNode;
        
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        
        while(originalNode != NULL){
            
            OldToNewNode[originalNode] = cloneNode;
            originalNode = originalNode -> next;
            cloneNode = cloneNode -> next;
        }
        
        //Step 3 - Clone the random pointers
        originalNode = head;
        cloneNode = cloneHead;
        
        while(originalNode != NULL){
            
            cloneNode -> arb = OldToNewNode[originalNode -> arb];
            originalNode = originalNode -> next;
            cloneNode = cloneNode -> next;
        }
        
        return cloneHead;
        
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore(); // Ignore the newline after T
    while (T--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        vector<int> arr;
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Node *head = NULL, *tail = NULL;
        for (int i = 0; i < arr.size(); ++i) {
            append(&head, &tail, arr[i]);
        }

        getline(cin, input);
        stringstream ss2(input);
        vector<int> arr2;
        while (ss2 >> number) {
            arr2.push_back(number);
        }

        Node *temp = head;
        for (int i = 0; i < arr2.size(); i += 2) {
            int a = arr2[i];
            int b = arr2[i + 1];

            Node *tempA = head;
            Node *tempB = head;
            for (int j = 1; j < a; ++j) {
                tempA = tempA->next;
            }
            for (int j = 1; j < b; ++j) {
                tempB = tempB->next;
            }

            tempA->arb = tempB;
        }

        Solution ob;
        Node *res = ob.copyList(head);

        if (validation(head, res)) {
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }
    }
    return 0;
}

// } Driver Code Ends