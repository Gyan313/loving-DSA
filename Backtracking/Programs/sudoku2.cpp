#include<bits/stdc++.h>
using namespace std;


bool isSafeRow(int** sudoku,int row,int val){
    for(int i=0;i<9;i++){
        if(sudoku[row][i]==val){
            return false;
        }
    }
    return true;
}

bool isSafeCol(int** sudoku,int col,int val){
    for(int i=0;i<9;i++){
        if(sudoku[i][col]==val){
            return false;
        }
    }
    return true;
}

bool isSafeBox(int** sudoku,int row,int col,int val){

    int rowFactor=row-(row%3);
    int colFactor=col-(col%3);

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(sudoku[i+rowFactor][j+colFactor]==val){
                return false;
            }
        }
    }
    return true;
}

bool isSafe(int** sudoku,int row,int col,int val){
    // check row
    //check col
    // check box (3by3)
    if(isSafeRow(sudoku,row,val) && isSafeCol(sudoku,col, val) && isSafeBox(sudoku,row,col,val)){
        return true;
    }
    return false;
}

bool correctPattern(int** sudoku,int row,int col){
    if (row == 9){
        return true;
    }
    
    if (col == 9){
        return correctPattern(sudoku, row + 1, 0);
    }
    
    if (sudoku[row][col] != 0){
        return correctPattern(sudoku, row, col + 1);
    }

    for(int i=1;i<=9;i++){
      if (isSafe(sudoku, row, col, i)) {
        sudoku[row][col] = i;
        if(correctPattern(sudoku,row,col+1)){
            return true;
        }
        sudoku[row][col]=0;
      }
    }
    return false;
}
int main(){
    int **sudoku=new int*[9];

    for(int i=0;i<9;i++){
        sudoku[i]=new int[9];
        string s;
        cin>>s;
        for(int j=0;j<s.length();j++){
            sudoku[i][j]=s[j]-'0';
        }
    }

    if(correctPattern(sudoku,0,0)){
        return true;
    }
    else{
        return false;
    }
    return 0;
}

