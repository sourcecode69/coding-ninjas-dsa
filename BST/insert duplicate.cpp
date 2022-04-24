BinaryTreeNode<int> * helper(BinaryTreeNode<int> * node){
    
    if(node ==NULL){
return NULL;
    }
  
     node->left = helper(node->left);
     node->right = helper(node->right);
      if(node->left==NULL){
        BinaryTreeNode<int> * temp = new BinaryTreeNode<int> (node->data);
        node->left = temp;
        return node;
    }
    if(node->left != NULL){
        BinaryTreeNode<int> * temp = new BinaryTreeNode<int> (node->data);
        BinaryTreeNode<int> * temp1 = node->left;
        node->left = temp;
        temp->left = temp1;
        return node;
    }
   
   
    
    
}



void insertDuplicateNode(BinaryTreeNode<int> *root) {
    // Write your code here
    if(root==NULL){
        return ;
    }
    root= helper(root);
    
}
