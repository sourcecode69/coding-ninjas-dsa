
//brute force (recursion)
int minhelp(int **input, int m, int n, int x, int y){
    if(x==m-1 && y==n-1){
        return input[x][y];
    }
    //base case 
    if(x<0 || y<0 || x>m|| y>n){
        return INT_MAX;
    }
    int a =INT_MAX;
    int b=a;
    int c =a;
    if(x<m-1){
   a = minhelp(input,m,n,x+1,y);}
    if(x<m-1 && y<n-1){
     b = minhelp(input,m,n,x+1,y+1);}
    if(y<n-1){
     c = minhelp(input,m,n,x,y+1);}
    
    return input[x][y] + min(a,min(b,c));
}


int minCostPath(int **input, int m, int n)
{
	//Write your code here
    
    return minhelp(input,m,n,0,0);
    
}



//by memoisation 
int helper(int **input, int m, int n, int x, int y,int **output){
    
     if(x==m-1 && y==n-1){
        return input[x][y];
    }
    if(x<0 || y<0|| x>m || y>n){
        return INT_MAX;//because we have to find minimum so cant be 0
    }
   //check if present.
    if(output[x][y]!=-1){
        return output[x][y];
    }
    else{
    int a = INT_MAX;
    int b = a;
    int c = a;
    if(x<m-1){
        a= helper(input,m,n,x+1,y,output);
    }
    if(x<m-1 && y<n-1){
       b=helper(input,m,n,x+1,y+1,output);
    }
    if(y<n-1){
        c= helper(input, m, n, x,y+1,output);
    }
    int t =  input[x][y] + min(a,min(b,c));
    output[x][y] = t;
return t;
    }
    
}
int minCostPath(int **input, int m, int n)
{
	//Write your code here
    //make a 2d output array.
    int **output = new int*[m];
    for(int i=0; i<m; i++){
        output[i] = new int[n];
    }
    //intitialise the array by -1.
      for(int i =0; i<m;i++){
          for(int j=0; j<n;j++){
              output[i][j]=-1;
          }
      }  
    
    
    
    return helper(input,m,n,0,0,output);
}


//by dynamic programming .






int minCostPath(int **input, int m, int n)
{
	//Write your code here
    int **out = new int*[m];
    for(int i =0; i<m; i++){
        out[i] = new int[n];
    }
    out[m-1][n-1]= input[m-1][n-1];
    //last row

    for(int i = n-2; i>=0; i--){
        out[m-1][i]= input[m-1][i] + out[m-1][i+1]; 
    }
    //last column.
    for(int i =m-2 ; i>=0; i--){
        out[i][n-1] = input[i][n-1] + out[i+1][n-1];
    }
    //
    for(int i = m-2; i >= 0; i--) {
		for(int j = n-2; j >= 0; j--) {
			out[i][j] = input[i][j] + min(out[i][j+1], min(out[i+1][j+1], out[i+1][j]));
		}
      
    }
      return out[0][0];
}

