void mirror(BInaryTreeNode<int> * root){
if(root == NULL){
  return;
}
  BinaryTreeNode<int> * temp= root->left;
  root->left= root-> right;
  root->right = temp;
  
  mirror(root->left);
  mirror(root->right);
  
  

}
