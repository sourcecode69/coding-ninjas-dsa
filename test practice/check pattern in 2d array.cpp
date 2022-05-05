// Online C++ compiler to run C++ program online
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

bool check(int arr[][20], int m , string s){
    for(int i =0; i<m; i++){
        string s1;
        for(int j =0; j<m ; j++){
             s1[i] = arr[i][j];
        }
        if(s1.find(s) != string::npos){
            return true;
        }
    }
      for(int i =0; i<m; i++){
        string s1;
        for(int j =0; j<m ; j++){
             s1[i] = arr[j][i];
        }
        if(s1.find(s) != string::npos){
            return true;
        }
    }
    return false;
}


int main() {
    // Write C++ code here
    int m =0;
    cin>> m;
    int arr[m][20];
    for(int i =0; i<m; i++){
        for(int j =0; j<m;j++){
            cin>>arr[i][j];
        }
    }
    int n =0;
    cin>>n;
    int input[n];
    for(int i =0; i<n; i++){
        cin>>input[i];
    }
    string s; 
    for(int i=0; i<n; i++){
        s[i]=input[i];//storing the array data in the string.to later check the string.
    }
    
    if(check(arr,m,s)){
        cout<<"yes"<<endl;
    }
    else{
        cout<<"no"<<endl;
    }
     

    return 0;
}
