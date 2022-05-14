#include<string>
int editDistance(string s1, string s2) {
	// Write your code here
    int m = s1.size();
    int n = s2.size();
    // base case
    if(m==0 && n==0){
        return 0;
    }
      if(m ==0 && n!=0){
        return  n;
    }
    if(n==0 && m!=0){
return  m;
    }
    int x =0;
   
    //recursive call
    if(s1[0] == s2[0]){
       x =  editDistance(s1.substr(1), s2.substr(1));
        return x;
    }
    else{
    int a = editDistance(s1.substr(1), s2);
        int b = editDistance(s1,s2.substr(1));
        int c = editDistance(s1.substr(1), s2.substr(1));
        
        return 1+ min(a,min(b,c));
    }
   
}


//memoisation 
int help(string s1, string s2, int **output){
       int m = s1.size();
    int n = s2.size();
    // base case
    if(m==0 && n==0){
        return 0;
    }
      if(m ==0 && n!=0){
        output[m][n] = n;
          return n;
    }
    if(n==0 && m!=0){
output[m][n] = m;
        return m;
    }
    if(output[m][n] != -1){
        return output[m][n];
    }
    int x =0;
   
    //recursive call
    if(s1[0] == s2[0]){
       x =  help(s1.substr(1), s2.substr(1),output);
    }
    else{
    int a = help(s1.substr(1), s2,output);
        int b = help(s1,s2.substr(1),output);
        int c = help(s1.substr(1), s2.substr(1),output);
         x =  1+ min(a,min(b,c));
      
    }
    output[m][n] = x;
return x;
}



int editDistance(string s1, string s2)
{
	//Write your code here
    int m = s1.size();
    int n = s2.size();
    int **output = new int *[m+1];
    for(int i =0; i<=m; i++){

    output[i] = new int[n+1];
    }
    for(int i =0; i<=m; i++){
        for(int j =0; j<=n; j++){
            output[i][j] = -1;
        }
    }
    
    return help(s1,s2,output);
    
}


// dynamic programming.




