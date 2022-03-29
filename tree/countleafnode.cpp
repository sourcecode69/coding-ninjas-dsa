/************************************************************
 
    Following is the structure for the TreeNode class

    template <typename T>
    class TreeNode {
     public:
        T data;
        vector<TreeNode<T>*> children;
    
        TreeNode(T data) {
            this->data = data;
        }
    
        ~TreeNode() {
            for (int i = 0; i < children.size(); i++) {
                delete children[i];
            }
        }
    };

************************************************************/

int getLeafNodeCount(TreeNode<int>* root) {
    // Write your code here
    if(root == NULL){
        return 0;
    }
    if(root->children.size() == 0){
        return 1;
    }
    int ans = 0 ;
    for(int i =0; i <root->children.size(); i++){
        int j =  ans + getLeafNodeCount(root->children[i]);
        ans = j;
    }
 return ans;
}

