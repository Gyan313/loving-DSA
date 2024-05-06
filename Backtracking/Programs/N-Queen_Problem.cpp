#include<bits/stdc++.h>
using namespace std;
int chessBoard[10][10];


bool isPossible(int n,int row,int col){

    //vertically up
    for(int i=row-1;i>=0;i--){
        if(chessBoard[i][col]==1){
            return false;
        }
    }

    // diagonally left
    for(int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
        if(chessBoard[i][j]==1){
            return false;
        }
    }

    //diagonaly right
    for(int i=row-1,j=col+1;i>=0 && j<n;i--,j++){
        if(chessBoard[i][j]==1){
            return false;
        }
    }

    return true;
}

void printConfig(int n,int row){

    if(row>=n){

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<chessBoard[i][j]<<" ";
            }
        }
        cout<<endl;
        return;
    }

    for(int i=0;i<n;i++){

        if(isPossible(n,row,i)){
            chessBoard[row][i]=1;
            printConfig(n,row+1);
            chessBoard[row][i]=0;
        }

    }
}


void nQueen(int n){
    memset(chessBoard,0, 10*10*sizeof(int));

    printConfig(n,0);
}

int main(){
    int n;
    cin>>n;
    nQueen(n);
    return 0;
}


