int countMinStepsToOne(int n)
{
	//Write your code here
  //brute force.
    //base case.
    if(n==1){
        return 0;
    }
    int a = INT_MAX;
    int b=a;
    int c=a;
    a = countMinStepsToOne(n-1);
    if(n%2==0){
    b=countMinStepsToOne(n/2);
        }
    if(n%3==0){
    c= countMinStepsToOne(n/3);
    }
    return 1+min(a, min(b,c));
    
}


//by dyanmic prigramming.
int countto1(int n){
 int * ans = new int[n+1];
    ans [0] = 0;
    ans [1]=0;
    ans[2] = 1;
    ans[3] = 1;
    int b=INT_MAX ;
    int c=INT_MAX;
    for(int i =4; i<=n; i++){
        b=c=n;
        if(i%2==0){
            b=ans[i/2];
        }
        if(i%3==0){
            c=ans[i/3];
        }
        ans[i]= 1+ min(ans[i-1], min(b,c));
    }
    return ans[n];
}


//memrization is when we store data while recursion.

