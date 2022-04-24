int getLCA(BinaryTreeNode<int>* root , int val1 , int val2){
    // Write your code here
    if(root==NULL){
        return -1;
    }
    if(root->data == val1|| root->data == val2){
        return root->data;
    }
    
    int x = getLCA(root->left,val1,val2);
    int y = getLCA(root->right,val1,val2);
    
    if(x != -1 && y ==-1){
       return x;
    }
    if(y != -1 && x == -1){
        return y;
    }
    if(x==-1 && y==-1){
      return -1;
    }
     else{
    return root->data;
    
}
}
