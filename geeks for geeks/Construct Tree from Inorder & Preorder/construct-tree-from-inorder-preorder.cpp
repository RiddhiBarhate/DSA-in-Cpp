//{ Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/

class Solution{
    public:
    int findPosition(int arr[], int element,int start, int end) {
    for(int i = start; i <= end; ++i) {
        if(arr[i] == element) {
                return i;
            }
        }
        return -1;
    }
    Node* buildTreeFromPreorderInorder(int inorder[], int preorder[], int size, int& preIndex, int inorderStart, int inorderEnd) {
        // base case
        if(preIndex >= size || inorderStart > inorderEnd) {
            return NULL;
        }
        
        // Step A:
        int element = preorder[preIndex++];
        Node* root = new Node(element);
        
        int pos = findPosition(inorder, element, inorderStart, inorderEnd);
        if(pos == -1) {
            return NULL;
        }
        
        // left call
        root->left = buildTreeFromPreorderInorder(inorder, preorder, size, preIndex, inorderStart, pos - 1);
        // right call
        root->right = buildTreeFromPreorderInorder(inorder, preorder, size, preIndex, pos + 1, inorderEnd);
        
        return root;    
    }
    Node* buildTree(int inorder[],int preorder[], int size)
    {
        int preIndex = 0;
        int inorderStart = 0;
        int inorderEnd = size - 1;
        Node* root = buildTreeFromPreorderInorder(inorder, preorder, size, preIndex, inorderStart, inorderEnd);
        return root;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends