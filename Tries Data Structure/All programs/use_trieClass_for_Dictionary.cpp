#include<iostream>
using namespace std;
#include "Trie_class.h"

int main(){
    Trie dictionary;
    dictionary.insert("gyan");
    cout<<dictionary.search("gyan")<<endl;
    dictionary.remove("gyan");
    cout<<dictionary.search("gyan");
    return 0;
}