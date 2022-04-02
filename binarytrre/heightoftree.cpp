int height(binarytreenode<int>* root){
int h =0;
  if(root==NULL){
    return h;}
  int l = height(root->left);
  int r = height(root->right);
  if(l>r){
    return l +1;}
  else 
    return r+1;

}
