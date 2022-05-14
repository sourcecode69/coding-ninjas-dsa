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
