int getLCA(BinaryTreeNode <int>* root , int a, int b) {
    //Write your code here
    if(root==NULL){
        return -1;
    }
    if(root->data == a || root->data == b){
        return root->data;
    }
    int x = getLCA(root->left, a, b);
    int y = getLCA(root->right, a,b);
    
    if(x !=-1 && y==-1){
return x;
    }
    else if(x==-1 && y!=-1){
        return y;
    }
    if(a==-1 && b == -1){
        return -1;
    }
    else{
       return root->data;
    }
}
