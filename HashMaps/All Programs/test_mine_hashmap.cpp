#include<iostream>
#include "implemetation_of_hashmaps.h"
using namespace std;

int main(){
    unorder_map<int> ourmap;
    for(int i=0;i<15;i++){
        char c='0'+i;
        string key="abc";
        key=key+c;
        int value=i+1;
        ourmap.insert(key,value);
        cout<<ourmap.loadFactor()<<endl;
    }
    return 0;
}