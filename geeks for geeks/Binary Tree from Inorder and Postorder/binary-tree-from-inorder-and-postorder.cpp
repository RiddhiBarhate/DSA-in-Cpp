//{ Driver Code Starts
/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL)
        return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}


// } Driver Code Ends
/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution {
  public:

    // Function to return a tree created from postorder and inoreder traversals.
    
    int findPosition(int arr[], int element,int start, int end) {
    for(int i = start; i <= end; ++i) {
        if(arr[i] == element) {
                return i;
            }
        }
        return -1;
    }
    
    Node* buildTreeFromPostorderInorder(int inorder[], int postorder[], int size, int& postIndex, int inorderStart, int inorderEnd) {
        // base case
        if(postIndex < 0 || inorderStart > inorderEnd) {
            return NULL;
        }
        
        // Step A:
        int element = postorder[postIndex--];
        Node* root = new Node(element);
        
        int pos = findPosition(inorder, element, inorderStart, inorderEnd);
        if(pos == -1) {
            return NULL;
        }
        
        // right call
        root->right = buildTreeFromPostorderInorder(inorder, postorder, size, postIndex, pos + 1, inorderEnd);
        
        // left call
        root->left = buildTreeFromPostorderInorder(inorder, postorder, size, postIndex, inorderStart, pos - 1);
        
        return root;    
    }
    
    Node *buildTree(int n, int in[], int post[]) {
        int postIndex = n - 1;
        int inorderStart = 0;
        int inorderEnd = n - 1;
        Node* root = buildTreeFromPostorderInorder(in, post, n, postIndex, inorderStart, inorderEnd);
        return root;
    }
};


//{ Driver Code Starts.

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++)
            cin >> in[i];
        for (int i = 0; i < n; i++)
            cin >> post[i];
        Solution obj;
        Node* root = obj.buildTree(n, in, post);
        preOrder(root);
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends