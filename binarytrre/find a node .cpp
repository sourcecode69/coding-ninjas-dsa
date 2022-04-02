bool isNodePresent(BinaryTreeNode<int> *root, int x) {
    // Write your code here
   /* if(root == NULL){
        return false;
    }
  //  bool y = false
    if(root->data == x){
        return true;
    }
    bool a = isNodePresent(root->left,x);
    bool b = isNodePresent(root->right,x);
    if(a||b){
        return true;
    }
    else
        return false;*/

    //both are correct.
    bool ans=false;
        if(root->data==x)
      ans =true;
   if(root->left) 
   {  bool leftans= isNodePresent(root->left,x);
      if(leftans)
          ans=leftans;
   }
    
    if(root->right)
    {   bool rightans= isNodePresent(root->right,x); 
      if(rightans)
          ans=rightans;
    }
   return ans; 
}
