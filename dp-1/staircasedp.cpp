long staircasedp(int n){  long ans[n+1];
    ans[0]=0;
    ans[1]=1;
    ans[2] = 2;
    ans[3]= 4;
    for(int i =4; i<=n; i++){
        ans[i]= ans[i-1]+ans[i-2]+ans[i-3];
    }
    return ans[n];
}
//by recursion.
int staircase(int n){
   if( n==0||n==1 || n==2){
        return n;
    }
    if(n==3){
        return 4;
    }
    long ans = staircase(n-1) + staircase(n-2) + staircase(n-3);
    return ans;
}
