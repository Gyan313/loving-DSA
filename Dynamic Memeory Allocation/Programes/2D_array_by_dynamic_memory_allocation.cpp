#include<iostream>
using namespace std;

int main(){
    int **p=new int*[1];
    for(int i=0;i<10;i++){
        p[i]=new int[4];
    }
    int a;
    for(int i=0;i<1;i++){
        for(int j=0;j<4;j++){
            cout<<"a= "<<endl;
            cin>>a; 
            p[i][j]=a;
        }
    }
    cout<<endl;
    for(int i=0;i<1;i++){
        for(int j=0;j<4;j++){
            cout<<p[i][j]<<endl;
        }
    }

    // Now we have to delete the memory allocated here dynamically
    for(int i=0;i<1;i++){
        delete [] p[i];
    }
    delete [] p;
    return 0;
}