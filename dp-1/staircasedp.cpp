  long ans[n+1];
    ans[0]=0;
    ans[1]=1;
    ans[2] = 2;
    ans[3]= 4;
    for(int i =4; i<=n; i++){
        ans[i]= ans[i-1]+ans[i-2]+ans[i-3];
    }
    return ans[n];
