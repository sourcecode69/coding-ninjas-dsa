int height(BinaryTreeNode<int> * root){
    if(root==NULL){
        return 0;
    }
    return 1+ max(height(root->left), height(root->right));
}

vector<int>* longestPath(BinaryTreeNode<int>* root) {
	// Write your code here
    
    if(root->left ==NULL && root->right ==NULL){
        vector<int>* v = new vector<int> ();
        v->push_back(root->data);
        return v;
    }
    int righth = 0;
    int lefth=0;
    if(root->left){
     lefth = height(root->left);
    }
    if(root->right){
    righth = height(root->right);
    }
    if(lefth > righth){
      vector<int> * l = longestPath(root->left);
        l->push_back(root->data);
        return l;
    }
    else if(lefth<righth){
        vector<int> * r = longestPath(root->right);
        r->push_back(root->data);
        return r;
    } 
}
