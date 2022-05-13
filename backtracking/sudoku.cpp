#include<bits/stdc++.h>
using namespace std;



bool issafe(int grid[][9], int row, int col , int num){
    for(int i =0; i<9; i++){
        if(grid[row][i] == num){
            return false;
        }
        if(grid[i][col] == num){
            return false;
        }
    }
    
    //now check in grid.
    int rowc = row-(row%3);
    int colc = col -(col%3);
    for(int i =0 ; i< 3 ; i++){
        for(int j =0; j<3; j++){
            if(grid[i+rowc][j+colc] == num){
                return false;
            }
        }
    }
    return true;
}

bool helper(int grid[][9], int row, int col){
if(row ==9){
    return true;
}    
    if(col == 9)
    {
        return helper(grid,row+1,0);
    }
if(grid[row][col] !=0){
    return helper(grid, row,col+1);
}
    for(int i =0; i<=9; i++){
        if(issafe(grid,row,col,i)){
            grid[row][col] = i;
            if(helper(grid,row,col+1)){
                return true;
            }
        }
        grid[row][col] = 0;
    }
return false;
}


bool solve(int grid[][9]){
return helper(grid,0,0 );
}



int main(){
    
    int grid[9][9];
    for(int i =0; i<9; i++){
        for(int j =0; j<9; j++){
            cin>>grid[i][j];
        }
    }
    if(solve(grid)){
cout<<"true";
    }
    else{
        cout<<"false";
    }
    
    return 0;
}
