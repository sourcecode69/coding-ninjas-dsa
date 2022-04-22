BinaryTreeNode<int>* helper(int *input, int s, int e){
    int mid = (s+e)/2;
    if(s>e){
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>( input[mid]);
    BinaryTreeNode<int>*left = helper(input,s,mid-1);
    BinaryTreeNode<int>* right = helper(input,mid+1,e);
    root->left = left;
    root->right= right;
    return root;
}


BinaryTreeNode<int>* constructTree(int *input, int n) {
	// Write your code here
    if(n==0){
        return NULL;
    }
  
helper(input,0,n-1);
}
