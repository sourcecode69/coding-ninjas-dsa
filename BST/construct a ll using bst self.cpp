/**********************************************************

	Following are the Binary Tree Node class structure and the 
	Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public: 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this->data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

	template <typename T>
 	class Node{
    	public:
    	T data;
    	Node<T> *next;
    
    	Node(T data) {
        	this->data = data;
        	this->next = NULL;
    	}
 	};

***********************************************************/


Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {
	// Write your code here
    if(root==NULL){
        return NULL;
    }
    if(root->left == NULL){
        Node<int> * rhead = constructLinkedList(root->right);
        Node<int> * head = new Node<int> (root->data);
        head->next = rhead;
    return head;  
    }
    if(root->right ==NULL){
         Node<int> * lhead = constructLinkedList(root->left);
         Node<int> * temp = lhead;
    Node<int> * head = new Node<int> (root->data);
    
         while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next = head;
        return lhead;
    }
    
    Node<int> * lhead = constructLinkedList(root->left);
    Node<int> * rhead = constructLinkedList(root->right);
    Node<int> * temp = lhead;
    Node<int> * head = new Node<int> (root->data);
    
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next = head;
    head->next = rhead;
    return lhead;
    
}
