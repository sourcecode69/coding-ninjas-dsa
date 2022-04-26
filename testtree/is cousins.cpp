bool issibling(BinaryTreeNode<int> * root, int d1, int d2){
    if(root==NULL){
        return false;
    }
    if(root->left && root->right){
        if(root->left->data == d1 && root->right->data == d2){
            return true;
        }
        if(root->left->data == d2 && root->right->data == d1){
            return true;
        }
        
    }
    if(root->left){
        issibling(root->left,d1,d2);
    } 
    if(root->right){
        issibling(root->right,d1,d2);
    }
}
//this checks if it is sibling of the same parent or not , so to chech the cousins we have to check .
//now function to find the level
int level(BinaryTreeNode<int>* root, int da, int l ){//level is l
    if(root==NULL){
        return 0;
    }
    if(root->data == da){
        return l;
    }
 int left = level(root->left, da,l+1);
    if(left!=0){
        return left;
    }
    
    int right = level(root->right, da, l+1);
}





bool isCousin(BinaryTreeNode<int> *root, int p, int q) {
    // Write your code here
    //now we check for the cousins
    if(root==NULL){
        return false;
    }
    if((level(root,p,1) == level(root,q,1)) && !issibling(root,q,p)){
        return true;
    }
    else
        return false;

}
