#include<bits/stdc++.h>
using namespace std;

bool findcorrectPos(int **sudoku,int& row,int& col){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(sudoku[i][j]==0){
                row=i;
                col=j;
                return true;
            }
        }
    }
    return false; 
}

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

bool correctPattern(int** sudoku){
    int row,col;
    if(!findcorrectPos(sudoku,row,col)){
        return true;
    }

    for(int i=1;i<=9;i++){
      if (isSafe(sudoku, row, col, i)) {
        sudoku[row][col] = i;
        if(correctPattern(sudoku)){
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

    if(correctPattern(sudoku)){
        return true;
    }
    else{
        return false;
    }
    return 0;
}