void printLevelWise(BinaryTreeNode<int> *root) {
    // Write your code here
    if(root==NULL){
        return ;
    }
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    q.push(NULL);

    while( q.size() !=0){
        BinaryTreeNode<int> *front = q.front();
        q.pop();
        
        if(front == NULL){
         if(q.size() == 0){
             break;
         }
            cout<<""<<endl;
             q.push(NULL);
        }
        else {
             cout<<front->data<<" ";
        if(front->left){
            q.push(front->left);
        }
        if(front->right){
            q.push(front->right);
        }  
        }
           
        
    }
    
}
