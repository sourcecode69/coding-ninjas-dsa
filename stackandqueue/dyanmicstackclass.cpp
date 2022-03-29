#include<iostream>
#include<climits>
using namespace std;

class stack{
    private:
    int nextindex;
    int *data;
    int capacity;
    
    public:
    stack(){
        int n =0;
        data = new int[totalsize];
        nextindex =0;
        capacity = 4;
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
    void push(int n ){
        if(nextindex == capacity){
            capacity = 2*capacity;
            int *newdata = new int[capacity];
            for(int i =0; i<capacity/2; i++){
                newdata[i] = data[i];
            }
            delete [] data;//deallocating array.

            data = newdata;
           // cout<<"stack full"<<endl;
            //return;
        }
        else {
        data[nextindex] = n ;
        nextindex++;
        }

    }
int pop(){
    if(nextindex==0){
        cout<<"stack empty";
        return 0;
    }
    nextindex--;
    return data[nextindex];
}

int top(){
    if(nextindex ==0){
        return 0 ;
    }
    else 
    return data[nextindex-1];
}

};


int main(){
    class stack<int> s(4);
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
