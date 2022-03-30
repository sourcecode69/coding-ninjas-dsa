//Given a generic tree, find and return the node for which sum of its data and data of all its child nodes is maximum. 
//In the sum, data of the node and data of its immediate child nodes has to be taken.


TreeNode<int>* maxSumNode(TreeNode<int>* root) {
    // Write your code here
    if(root == NULL){
        return root;
    }
    int sumroot = 0;
    TreeNode<int> *ans = root;
    sumroot = root->data;
    // sum of root node and its children.
    for(int i =0; i < root->children.size(); i++){
        sumroot = sumroot + root->children[i]->data;
    }
    //now for recursion.
    for(int i =0; i< root->children.size(); i++){
        TreeNode<int> * sans = maxSumNode(root->children[i]);
        int smallsum = sans->data;
        for(int j =0; j < sans->children.size(); j++){
            smallsum += sans->children[j]->data;
        }
        
        if(sumroot < smallsum){
            ans = sans;
            sumroot=smallsum;
        }
    }
    
   return ans;
  
   
}
