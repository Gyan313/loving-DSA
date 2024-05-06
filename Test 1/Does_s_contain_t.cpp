#include<iostream>
using namespace std;

// Wrong soln
int len(char large[]){
    int i=0;
    while(large[i]!='\0'){
        i++;
    }
    return i;
}

bool checksequenece(char large[] , char*small) {
    if(len(small)==1){
        return true;
    }
    int k=0,j=0;
    if(len(small)!=1){
        for(int i=0;i<len(large);i++){
            if(small[0]==large[i]){
                k=i;
            }
            if(small[1]==large[i]){
                j=i;
            }
        }
        if(k>j){
            return false;
        }
        else{
            checksequenece(large, small+1);
        }
    }
}

int main()
{
	char large[10000];
	char small[10000];
	cin>>large;
	cin>>small;
	bool x=checksequenece(large , small);

	if(x)
		cout<<"true";
	else
		cout<<"false";

}
