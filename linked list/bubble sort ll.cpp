Node *bubbleSort(Node *head)
{
    if(head==NULL){
        return head;
    }
	// Write your code here
    Node* temp = head;
    while(temp!=NULL){
        Node* tem1 = temp->next;
        while(tem1!=NULL){
            if(temp->data > tem1->data){
                int tem = temp->data;
                temp->data = tem1->data;
                tem1->data= tem;
            }
            tem1=tem1->next;
        }
        temp=temp->next;
    }
    return head;
}
