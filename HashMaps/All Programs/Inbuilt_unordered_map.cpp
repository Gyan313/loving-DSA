#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

int main(){
    unordered_map<string,int> unomap;

    //insert
    // first way
    pair<string,int> p("abc",1);
    unomap.insert(p);

    //2nd way
    unomap["abc"]=1;
    unomap["def"]=2;

    // find or access
    cout<<unomap["abc"]<<endl;
    cout<<unomap.at("def")<<endl;

    cout<<"size: "<<unomap.size()<<endl;
    cout<<unomap["ghi"]<<endl;
    cout<<"size: "<<unomap.size()<<endl;

    // check presence
    if(unomap.count("ghi")>0){
        cout<<"present in map"<<endl;
    }

    //delete
    unomap.erase("ghi");
    if(unomap.count("ghi")>0){
        cout<<"present in map"<<endl;
    }
    else{
        cout<<"not present in map"<<endl;
    }

    unomap["jkf"]=1;
    unomap["jkf"]=5;
    cout<<unomap.count("jkf")<<endl;
    cout<<unomap["jkf"];
    return 0;
}