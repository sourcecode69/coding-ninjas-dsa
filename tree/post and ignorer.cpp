BinaryTreeNode<int> * build(int *pos, int *in, int poss,int poe, int ins, int ine){
    
    if(poss > poe ){
        return NULL;
    }
    int rootdata = pos[poe];
    int rooti =-1;
    for(int i = ins; i <= ine; i++){
        if(rootdata == in[i]){
            rooti = i;
            break;
        }
    }
    
    int lps = poss;//post ka start
    int lis=ins;
    int lie = rooti-1;
    int lpe= lps + lie-lis;
    // now for the right tree
    int rps = lpe+1;
    int ris=rooti+1;
    int rie=ine;
    int rpe = poe-1;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootdata);
    root->left = build(pos,in,lps,lpe,lis,lie);
    root->right = build(pos,in,rps,rpe,ris,rie);
    return root;
    
}

BinaryTreeNode<int>* buildTree(int *postorder, int postLength, int *inorder, int inLength) {
    // Write your code here
    return build(postorder,inorder,0,postLength-1,0,inLength-1);
    
}
