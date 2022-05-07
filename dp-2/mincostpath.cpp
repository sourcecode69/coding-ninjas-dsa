
//brute force (recursion)
int minhelp(int **input, int m, int n, int x, int y){
    if(x==m-1 && y==n-1){
        return input[x][y];
    }
    //base case 
    if(x<0 || y<0 || x>m|| y>n){
        return 0;
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
