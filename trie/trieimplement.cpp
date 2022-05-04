class TrieNode {
   public:
    char data;
    TrieNode **children;
    bool isTerminal;

    TrieNode(char data) {
        this->data = data;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie {
    TrieNode *root;

   public:
    Trie() { 
        root = new TrieNode('\0'); 
    }

    void insertWord(TrieNode *root, string word) {
        // Base case
        if (word.size() == 0) {
            root->isTerminal = true;
            return;
        }

        // Small Calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursive call
        insertWord(child, word.substr(1));
    }

    void insertWord(string word) { 
        insertWord(root, word); 
    }
    bool searchhelp(TrieNode * root, string word){
        //base case
        if(word.size() == 0 && root->isTerminal ==true){
            return true;
        }
        else if (word.size()==0 &&root-> isTerminal== false)
        {
            return false;
        }
               
        // small calculation
        int index = word[0] -'a';
     TrieNode* child;
        if(root->children[index] == NULL){
            return false;
        }
        else{
            child = root->children[index];
        }
         bool small = searchhelp(child, word.substr(1));
        
        return small; 
    }

    bool search(string word) {
        // Write your code here
        bool s = searchhelp(root,word);
        return s;
        
    }
   //remove function.
   void removehelepr(TrieNode* root, string word){
    //base case.
    if(word.size() == 0){
        root->isTerminal = false;
    }
    //small calculation.
    int index = word[0] -'a';
    TrieNode*child;
    if(root->children[index] ==NULL){
        return ;
    }
    else{
        child = root->children[index];
    }
    removehelepr(child,word.substr(1));

    // now deleteing, backstracking smaj le .
    //jab ye delete kr dega tab return upar aaega tab dellte the data.
    if(child->isTerminal == false){
        for(int i =0 ; i<26; i++){
            if(child->children[i] != NULL){
                return;
            }
        }
        // delete the node from the tree.
        delete child;
        //now root ke index par bhi null kr diya
        root->children[index] = NULL;

    }
}

    void remove(string word){
      removehelepr(root,word);
    }
};
