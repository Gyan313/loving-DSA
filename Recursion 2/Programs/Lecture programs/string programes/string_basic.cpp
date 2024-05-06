#include<iostream>
using namespace std;

int main(){
    string *s=new string("gyan dev");
    cout<<s<<endl;
    cout<<*s<<endl;

    string sp="gyan sharma";
    cout<<sp[2]<<endl;

    cout<<sp.size()<<endl;
    cout<<sp.length()<<endl;
    cout<<sp.substr(2)<<endl;
    cout<<sp.substr(2,5);
    delete s;
    return 0;
}