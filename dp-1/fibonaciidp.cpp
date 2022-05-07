#include<iostream>
using namespcae std;

int fibrecur(int n){
    if(n<=1){
        return 1;
    }
    return fibrecur(n-1) + fibrecur(n-2);
    //function for nth fibbonacci number.
}

int fibhelpr(int n, int*ans){
if(n<=1){
    return 1;
}

//check if answer is already there.
if(ans[n] != -1){
    return ans[n];
}
int a = fibhelpr(n-1,ans);
int b = fibhelpr(n-2,ans);
//now save it 
ans[n] = a+b;
return ans[n];
}

int fibdp(int n){
    int *ans = new int[n+1];
    //intitialize the array .
    for(int i =0; i<=n; i++){
        ans[i]=-1;
    }
    return fibhepr(n, ans);
}


//fibbonacci number by iterative.



int fibloop(int n ){
    int * ans = new int[n+1];
    ans[0]=0;
    ans[1]=1;
    for(int i =2; i<=n; i++){
        ans[i]=ans[i=2]+ans[i-1];
    }
    return ans[n];
}
int main(){

}
