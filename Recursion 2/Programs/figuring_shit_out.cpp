#include<iostream>
#include<string>
using namespace std;

int return_keypad_code(int n,string output[]){
    if(n<=1){
        return 0;
    }

    string input;
    switch(n%10){
        case 2:
            input = "abc";
            break;
        case 3:
            input = "def";
            break;
        case 4:
            input = "ghi";
            break;
        case 5:
            input = "jkl";
            break;
        case 6:
            input = "mno";
            break;
        case 7:
            input = "pqrs";
            break;
        case 8:
            input = "tuv";
            break;
        case 9:
            input = "wxyz";
            break;
    }

    // still broken, next time see hint on coding ninjas.

    int smalloutput = return_keypad_code(n/10,output);
    if(smalloutput == 0){
        for(int i=0;i<input.size();i++){
            output[i] = input[i];
        }
        return input.size();
    }
    else{
        int count = 0;
        int size_output = input.size()*smalloutput;
        for(int i=0;i<size_output;i++){
            output[i+3] = output[i];
        }
        for(int i=0;i<input.size();i++){
            for(int j=count;j<(smalloutput);j++){
                output[j] = output[j] + input[i];
                count++;        
            }
            smalloutput = smalloutput + count;
        }
        return count;
    }
}

int main(){
    int n;
    cin>>n;
    string* output = new string[1000000];
    int count = return_keypad_code(n,output);
    for(int i=0;i<count && i<1000000;i++){
        cout<<output[i]<<endl;
    }
    return 0;
}