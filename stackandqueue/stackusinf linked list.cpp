#include<iostream>
using namespace std;

template<typename t>
class Node{
public : 
t data;
Node<t> next;

//this is a default constructor.
Node(t data){
     this->data = data;
     next = NULL;
}
};

class stack{
public:
Node<t> *head;
int size ;
stack(){
   head = NULL;
   size =0;
}

getsize(){
    return size;
}
isempty(){
    if(size ==0){
        return true;
    }
    else 
    return false;
}

void push(t x){
    Node<t> *newnode = new Node(x);
    newnode->next = head;
    head = newnode;
    size++;
}
t pop(){
    if(size ==0){
        return -1;
}
size--;
int a = head->data;
head = head->next;
return a;
}

t top(){
    return head->data;
}

};






int main(){

}
