int minCount(int n)
{
	//Write your code here
  //brute force via recursion, it give runtine error
       
    if(sqrt(n) - floor(sqrt(n)) == 0){
        return 1;
    }
  
if(n<=3){
    return n;
}
    int ans=n;
    for(int i =1; i*i <=n; i++){
        ans = min(ans , 1+ minCount(n-i*i));
    }
    
    return ans;
}


// memorization of mincount


int minhelp(int n , int *ans){
    if(sqrt(n) - floor(sqrt(n)) == 0){
        ans[n] = 1;
        return ans[n];
    }
    if(n<=3){
        ans[n] = n;
        return n;
    }
    
    int an =n;
    if(ans[n] != -1){
        return ans[n];
    }
    else
        
    for(int i =1; i*i<=n; i++){
        ans[n] = min(an, 1+ minhelp(n-i*i,ans));
    }
    return ans[n];
}



int minCount(int n)
{
	//Write your code here
int * ans = new int[n+1];
    //intitializiting the garvage value.
    for(int i =0; i<=n; i++){
        ans[i] = -1;
    }
    return minhelp(n, ans);

}

//via dynamic programming.
  
int minCount(int n)
{
	//Write your code here
    if ( sqrt (n) -floor(sqrt(n))==0)  return 1;
    int arr[n+1];
    int ans= n;
    arr[0]=0;
    arr[1] = 1;
    arr[2]=2;
    arr[3] = 3;
    for(int i =4; i<=n; i++){
        arr[i] = i;
        for(int j =1; j <= ceil(sqrt(i)); j++){
            int temp = j*j;
            if(temp > i){
                break;
            }
            else
            {
                arr[i] = min(arr[i], 1+ arr[i-temp]);
            }
        }
    }
    return arr[n];
}
