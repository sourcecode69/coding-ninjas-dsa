// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int hcf(int a, int b){
    if(b==0){
       return a; 
    }
    return hcf(b, a%b);
}

long long lcm(int arr[], int n ){
    long long ans = arr[0];
  for (int i = 1; i < n; i++)
      {
           ans = (((arr[i] * ans))/(hcf(arr[i], ans)));
      }
    return ans;
}


int main() {
    // Write C++ code here
    int m=0;
    int n=0;
    cin>>m;
    cin>>n;
     int l = n-m+1;
  int arr[l];
  for(int i =0; i<l; i++){
      arr[i]= m+i;//storing all numbers.
  }
    //m will always be smaller than n.
   long long a= lcm(arr,l);
   cout<<a;
    return 0;
}
