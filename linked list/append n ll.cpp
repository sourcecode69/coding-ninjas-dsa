Node *appendLastNToFirst(Node *head, int n)
{
    //Write your code here
    Node*temp = head;
    int l=0;
    while(temp!=NULL){
        l++;
        temp = temp->next;
    }
    // l is legth of linked list.
    if(head ==NULL){
        return NULL;
    }
    if(l ==n){
        return head;
    }
    
    Node* tem1=head;
    Node*tem2 = head;
    for(int i =1; i< (l-n); i++){
        tem1=tem1->next;
    }
    for(int i =1; i< l; i++){
        tem2=tem2->next;
    }
    tem2->next = head;
    head= tem1->next;
    tem1->next = NULL;
    
    return head;
        
    
}
