#include<climits>
#include<algorithm>
int balancedBTs(int h) {
    // Write your code here
  //brute force recursive.
    if(h<=1){
        return 1;
    }
    int a = balancedBTs(h-1);
    int b= balancedBTs(h-2);
   //beacuse it can go out of range so we have to typecast.
    int mod= (int)(pow(10,9) +7);
    int temp1= (int)(((long)(a) *a)%mod);
    int temp2=(int)(((long)(2*a) *b)%mod);
    int ans = (int) ((temp1+temp2)%mod);
    
    return ans ;
}

// dp approach.
#include<climits>
#include<algorithm>
int balancedBTs(int n) {
    // Write your code here
    int arr[n+1];
    arr[0]=1;
    arr[1] = 1;
    int mod= (int)(pow(10,9)+7);
    //made the modulo interger by type casting as pow return long.
    
    for(int i =2; i<=n; i++){
        int t1= arr[i-1];
        int t2= arr[i-2];
        int te1= (int)((long(t1)*t1) %mod);
        int te2= (int)((long(2*t1)*t2) %mod);
       arr[i] = (int)((te1+te2)%mod);
    }
    return arr[n];
}


//memorisation cause it is important ans of order o(n)
#include<climits>
#include<algorithm>
int balancedhelp(int n, int *ans){
    if(n<=1){
        return ans[n];
    }
    if(ans[n] !=-1){
        return ans[n];
    }
    else{
    int mod = (int)(pow(10,9)+7);
    int a = balancedhelp(n-1,ans);
    int b = balancedhelp(n-2,ans);
    
    int t1 = (int)(((long)(a)*a)%mod);
    int t2 = (int)(((long)(2*a)*b)%mod);
   ans[n] = (int)((t1+t2)%mod);
}
    return ans[n];
}





int balancedBTs(int n) {
    // Write your code here
    int *ans= new int[n+1];
    ans[0]=1;
    ans[1]=1;
    for(int i =2; i<=n; i++){
        ans[i] = -1;
    }
    return balancedhelp(n,ans);
}
