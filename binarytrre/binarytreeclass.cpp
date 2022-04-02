
#include<iostream>
template<typename t> ;
class binarytree(){
    public:
    t data;
    binarytree *left;
    binarytree *right;

    binarytree(t data){
this->data = data;
    }
    ~binarytree(){
        delete left;
        delete right;
    }
}

using namespace std;

void print(binarytree<int> root){
    if(root==NULL){
        return ;
    }
      cout<<root->data<<":";
      if(root->left !=NULL){
          cout<< "l" << root->left->data;
      }
      if(root->right !=NULL){
          cout<< "r" << root->right->data;
      }
      cout<<""<<endl;
      print(root->left);
      print(root->right);
}
binarytree<int>* takeinput(){
      int rootdata;
      cout<<"enter root data"<<endl;
      cin>>rootdata;
      if(rootdata == -1){
          return NULL;
      }
      binarytree<int> *root= new binarytree<int>(rootdata);
binarytree<int>node1 = takeinput();
binarytree<int>node 2 = takeinput();
root->left = node1;
root->right = node2;
return root;
}

binarytree<int>* takeinputlevel(){
    int rootdata;
    cout<<"enter data"<<endl;
    cin>>rootdata;
    if(rootdata ==-1){
        return NULL;
    }
    binarytree<int>* root = new binarytree<int> (rootdata);
    queue<binarytree<int> * > pendingnode;
    pendingnode.push(root);
    while(pendingnode !=0){
        binarytree<int> *front = pendingnode.front();
        pendingnode.pop();
        cout<<"enter left child of "<<front->data;
        int leftchilddata;
        cin>>leftchilddata;
        if(leftchilddata != -1){
            
        
        binarytree<int> *lchild = new binarytree<int>(leftchilddata);
        front->left = lchild;
        pendingnode.push(lchild);
    }


cout<<"enter right child of "<<front->data;
        int rightchilddata;
        cin>>rightchilddata;
        if(rightchilddata != -1){
            
        
        binarytree<int> *rchild = new binarytree<int>(rightchilddata);
        front->right = rchild;
        pendingnode.push(rchild);
    }

    }
    return root;
}



int main(){
   
  /* binarytree<int> * root = new binarytree<int>(1);
   binarytree<int> *node1 = new binarytree<int>(2);
   binarytree<int> *node2 = new binartree<int>(3);
   root->left = node1;
   root->right= node2;
   // now this will take forever for lagre trees.
   */
    binarytree<int> *root = takeinputlevel();
    print(root);

    return 0;
}
