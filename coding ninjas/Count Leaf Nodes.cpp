int inOrder(BinaryTreeNode<int> *&root, int &count){
    //base case
    if(root == NULL)
        return 0;

    inOrder(root -> left, count);

    //leaf nodes
    if(root -> left == NULL && root -> right == NULL)
        count++;

    inOrder(root -> right, count);

    return count;
}

int noOfLeafNodes(BinaryTreeNode<int> *root){
    int count = 0;
    inOrder(root, count);

    return count;
}