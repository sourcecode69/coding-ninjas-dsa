void helper(TreeNode<int>*root, int d){
    if(root==NULL){
        return;
    }
    root->data= d;
    for(int i =0; i< root->children.size(); i++){
        helper(root->children[i],d+1);
    }
}
void replaceWithDepthValue(TreeNode<int>* root) {
    // Write your code here
   if(root == NULL){
       return;
   }
    int d =0;
    helper(root,d);
}
