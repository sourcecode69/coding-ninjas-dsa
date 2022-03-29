Given a generic tree and an integer x, check if x is present in the given tree or not.
Return true if x is present, return false otherwise.



bool containsX(TreeNode<int>* root, int x) {
    if(root->data==x)
    	return true;
    
    
   bool ans=false;
    for(int i=0;i<root->children.size();i++)
    {
        bool smallans=containsX(root->children[i],x);
        if(smallans!=ans && smallans==true)
            ans=smallans;
    }
    
   return ans;
}
