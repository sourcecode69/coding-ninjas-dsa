int allIndexes(int input[], int size, int x, int output[]) {
	  if(size == 0)
        return 0;
    int smallCount= allIndexes(input, size -1, x, output);
     if(input[size -1] == x)
     {
         output[smallCount] = size -1;
         return smallCount +1;
     } else {
         return smallCount;
     }
}

----------------------------------------------------------------------------------------------------------------------------------------------------
int allIndexes(int input[], int size, int x, int output[]) {
 
   if(size==0) 
       return 0;
    int ans =allIndexes(input+1,size-1,x,output);

   // output[k]=output[k]+1;k++;
    if(input[0]==x){
        if(ans!=0)  // if output contains previous indexes
        {
  			for(int i=ans-1 ;i>=0;i--)  // increment their index and shift them 1 right side as we have to add
                //at output[0] the current index
            {
					output[i]++;
                output[i+1]=output[i];
                
            }
        }
        
        output[0]=0; 
        return ans+1;
    } 
    else
    {    //just incrmemnt index
        for(int i=ans-1 ;i>=0;i--)
            {
					output[i]++;
                //output[i+1]=output[i];
            }
     return ans;   
    }
      
}
--------------------------------------------------------------------------------------------------------------------------------------------------------------
#include<iostream>

using namespace std;

void help(int input[],int size,int x, int i, int *k,int output[])
{
    if(i==size)
        return;
    if(input[i]==x)
    {
        output[0]=i;
        output++;
        *k=*k+1;
    }
    help(input,size,x,i+1,k,output);
}
int allIndexes(int input[], int size, int x, int output[]) {
  
    int i=0;int k=0;
    help(input,size,x,i,&k,output);
    return k;

}


int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    int x;
    
    cin >> x;
    
    int *output = new int[n];
    
    int size = allIndexes(input, n, x, output);
    for(int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }
    
    delete [] input;
    
    delete [] output;
    

}
