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
#include<bits/stdc++.h> 
int maxi(BinaryTreeNode<int> * root){
   if(root==NULL){
       return 0;
   }
   
    int max1 = INT_MIN;
    if(root->data > max1){
        max1 = root->data;
    }
    int lm = maxi(root->left);
    int rm = maxi (root->right);
return max(root->data,max(rm,lm));
}

int mini(BinaryTreeNode<int> * root){
   if(root==NULL){
       return INT_MAX;
   }
    int min1 = INT_MAX ;
    if(root->data <min1){
        min1 = root->data;
    }
    int lm = mini(root->left);
    int rm = mini (root->right);
return min(root->data,min(rm,lm));
}
bool isBST(BinaryTreeNode<int> *root) {
	// Write your code here
      if(root ==NULL){
        return true;
    }
    int leftmax = maxi(root->left);
    int rightmin = mini(root->right);
bool out = (root->data > leftmax) && (root->data <= rightmin) && isBST(root->left) && isBST(root->right);
return out;

}
