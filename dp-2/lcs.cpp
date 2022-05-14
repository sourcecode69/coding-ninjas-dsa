#include<iostream>
using namepsace std;


int lcs (string s, string t){
    //base case
    if(s.size()==0 || t.size()==0){
        return 0;
    }
    //recursive call
    if(s[0]==t[0]){
        return 1 +  lcs(s.substr(1), t.substr(1));
    }
    else{
    int a = lcs(s.substr(1),t);
    int b= lcs(s,t.substr(1));
    int c = lcs(s.substr(1), t.substr(1));
    return max(a,max(b,c));
    }
}

int main(){
     string s = "abcs";
     string t = "acs";
     cout<< lcs(s,t);
    return 0;
}


/ lcs by memoisation.
int lcsmem (string s, string t, int **output){
    //length for i and j.
    int m = s.size();
    int n = t.size();

    //base case
    if(s.size()==0 || t.size()==0){
        return 0;
    }
    // check if answer already present.
if(output[m][n] != -1){
    return output[m][n];
}
    int ans =0;
    //recursive call
    if(s[0]==t[0]){
     ans =  1 +  lcsmem(s.substr(1), t.substr(1), output);
    }
    else{
    int a = lcsmem(s.substr(1),t,outpu);
    int b= lcsmem(s,t.substr(1),output);
    int c = lcsmem(s.substr(1), t.substr(1),output);
     ans = max(a,max(b,c));
    }
output[m][n] =  ans;
return ans;
}


//dp 
int lcsdp(string s, string t){
int m = s.size();
int n = t.size();
int **output = new int*[m+1];
for(int i =0; i<m+1; i++){
    output[i]= new int[n+1];
}
//2d array made here.

for(int i =0; i<=n; i++){
    output[0][i] = 0;
}
for(int i =0; i<=m; i++){
    output[i][0] = 0 ;

}
for(int i =1; i<-m; i++){
    for(int j = 1; j<=n; j++){
        //i and j are length of the string dot forget that.
        //check if first character matches.
        if(s[m-i] == t[n-j]){
            output[i][j] = 1+output[i-1][j-1];
        }
        else
        {
            output[i][j] = max(output[i-1][j-1], max(output[i-1][j],output[i][j-1]));
        }
    }
}


return output[m][n];

}
