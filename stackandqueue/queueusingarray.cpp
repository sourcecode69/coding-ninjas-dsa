#include <iostream>
using namespace std;

class queue{
    private:
    t *data;
    int n ;//nextindex
    int f; //frontindex
    int size;
    int capacity;
    public :
    queue(int s){
        t data = new int[s];
        n =0;
        f=-1;
        size =0;
        capacity = s;
    }
void enque(t a){

    // if( n == s && size < s){
    //     n = 0;
    //     data[n] = a;
    //     n++;
    //     size++;
    //     continue;
    // }
    if(size == capacity){
        cout<<"full mfs !"<<endl;
        return;
    }
    data[n] = a;
    if(f==-1){
        f=0;
    }
    n= (n+1)%capacity;
    size++;
}
t front (){
    if(size ==0){
        cout<<"empty"<<endl;
        return 0;
    }
    else 
    return data[f];
}
int deque(){
    if(size ==0){
        cout<<"empty"<<endl;
        return 0;
    }
    t t1= data[f];// t is a typename
    f= (f+1) %capacity;
    size--;
    // jaise hi queue empty ho gyi vaise hi vapas reset kr do, not neccessay but good
    
    if(size ==0){
        f=-1;
        n =0;
    }
    return t1;
}
int getsize(){
    return size;
}
bool isempty(){
    if(size == 0){
        return true;
    }
    else 
    return false;
}



};


int main(){

}
