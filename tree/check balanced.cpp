/**********************************************************
	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public : 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this -> data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

***********************************************************/
int height(BinaryTreeNode<int> *root){
     
int h =0;
  if(root==NULL){
    return h;
  }
  int l = height(root->left);
  int r = height(root->right);
  if(l>r){
    return l +1;}
  else 
    return r+1;
}


bool isBalanced(BinaryTreeNode<int> *root) {
	// Write your code here
    if(root==NULL){
        return true;
    }
    int rh = height(root->right);
    int lh = height(root->left);
  
    if((abs(rh-lh) == 0 || abs(rh-lh) == 1 )&& isBalanced(root->right) && isBalanced(root->left)){
        return true;
    }
    return false;
 
    
}
