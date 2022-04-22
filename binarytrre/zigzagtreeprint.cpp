#include<stack>

void zigZagOrder(BinaryTreeNode<int> *root) {
    // Write your code here
    stack<BinaryTreeNode<int>*> s;
    stack<BinaryTreeNode<int>*> q;
    if(root==NULL){
        return;
    }
    
    s.push(root);
    while(!s.empty() || !q.empty()){
        while(!s.empty()){
        BinaryTreeNode<int>* top = s.top();
        s.pop();
        cout<<top->data<<" ";
        if(top->left){
            q.push(top->left);
        }
            if(top->right){
                q.push(top->right);
            }
        
    }
        cout<<""<<endl;
        while(!q.empty()){
            BinaryTreeNode<int> * top = q.top();
            q.pop();
            cout<<top->data<<" ";
            if(top->right){
                s.push(top->right);
            }
            if(top->left){
                s.push(top->left);
            }

        }
                    cout<<""<<endl;
    }
    
    
}
