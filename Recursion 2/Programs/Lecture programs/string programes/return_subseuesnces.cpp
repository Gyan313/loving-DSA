#include<iostream>
using namespace std;

int subsequences(string input,string output[]){
    if(input.empty()){
        output[0]="";
        return 1;
    }
    string smallstring = input.substr(1);
    int smalloutput=subsequences(smallstring,output);
    // "smalloutput" is length of "output" array at each recursive step...
    for(int i=0;i<smalloutput;i++){
        output[i+smalloutput]=input[0]+output[i];
    }
    return 2*smalloutput;
}
int main(){
    string s;
    cin>>s;
    string *o=new string[10000];
    int count=subsequences(s,o);
    for(int i=0;i<count;i++){
        cout<<o[i]<<endl;
    }
    delete [] o;
    return 0;
}


// When using vector as the output array...
/*
void return_subsequences(string s,vector<string>& arr){
    if(s.empty()){
        arr.push_back(s);
        return;
    }
    cout<<s<<" ";
    return_subsequences(s.substr(1),arr);
    int len = arr.size();
    for(int i=0;i<len;i++){
        string str = s[0] + arr[i];
        arr.push_back(str);
    }
}   

int main(){
    string s;
    getline(cin,s);
    vector<string> v;
    return_subsequences(s,v);
    cout<<v.size()<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v.at(i)<<endl;
    }
    return 0;
} 
*/