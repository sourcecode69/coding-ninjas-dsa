vector<int>* getPath(BinaryTreeNode<int> *root , int k) {
	// Write your code here
        if(root==NULL){
        return NULL;
    }
     
    if(root->data ==k ){
        vector<int> * output = new vector<int>;
        output->push_back(root->data);
        return output;
    }
    vector<int> * leftout = getPath(root->left, k);
    if(leftout !=NULL){
        leftout->push_back(root->data);
        return leftout;
    }
    vector<int> * rightout = getPath(root->right, k);
    if(rightout != NULL){
        rightout->push_back(root->data);
        return rightout;
    }
    else{
        return NULL;
    }
