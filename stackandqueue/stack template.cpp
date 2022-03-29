#include<iostream>
#include<climits>
using namespace std;
template <typename T>
class stack{
    private:
    int nextindex;
    T *data;
    int capacity;
    
    public:
    stack(int totalsize){
        int n =0;
        data = new T[totalsize];
        nextindex =0;
        capacity = totalsize;
    }
public:
    int size(){
        return nextindex;
    }
    bool sempty(){
        if(nextindex==0){
            return true;
        }
        else{ 
        false;
            
        }
    }
    void push(T n ){
        if(nextindex == capacity){
            cout<<"stack full"<<endl;
            return;
        }
        else {
        data[nextindex] = n ;
        nextindex++;
        }

    }
T pop(){
    if(nextindex==0){
        cout<<"stack empty";
        return 0;
    }
    nextindex--;
    return data[nextindex];
}

T top(){
    if(nextindex ==0){
        return 0 ;
    }
    else 
    return data[nextindex-1];
}

};


int main(){
    class stack s(4);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

cout<<s.pop()<<endl;
cout<<s.pop()<<endl;
//cout<<s.pop()<<endl;
cout<<s.pop()<<endl;
cout<<s.top()<<endl;
cout<<s.top()<<endl;
s.push(20);
cout<<s.top()<<endl;
cout << s.size() <<endl;
//cout<< s.sempty() <<endl;
return  0;

}
