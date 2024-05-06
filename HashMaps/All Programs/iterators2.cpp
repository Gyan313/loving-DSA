#include<iostream>
#include<unordered_map>

using namespace std;

int main(){
    unordered_map<string,int> unmap;
    unmap["abc"]=1;
    unmap["def"]=2;
    unmap["ghi"]=3;
    unmap["jkl"]=4;
    unordered_map<string,int>::iterator it1=unmap.find("abc");

    unmap.erase(unmap.begin(),unmap.end());
    while(it1!=unmap.end()){
        cout<<"key: "<<it1->first<<" value: "<<it1->second<<endl;
        it1++;
    }
    return 0;
}