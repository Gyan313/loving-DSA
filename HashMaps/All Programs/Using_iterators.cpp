#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>

using namespace std;

int main(){
    // iterator on vector
    vector<int> v={1,2,3,4,5};
    vector<int>::iterator it=v.begin();

    v.erase(it,it+3); // delete elements from index 0 to 2 (not 3)
    
    while(it!=v.end()){
        cout<<*it<<" ";
        it++;
    }
    cout<<endl;

    // iterator on unordered map
    unordered_map<string,int> unmap;
    unmap["abc"]=1;
    unmap["def"]=2;
    unmap["ghi"]=3;
    unmap["jkl"]=4;

    unmap.erase(unmap.begin(),unmap.end()); // delete whole unordered map
    if(unmap.empty()){
        cout<<"hey hey hey"<<endl;
        exit(1);
    }

    unordered_map<string,int>::iterator it1=unmap.begin();
    
    while(it1!=unmap.end()){
        cout<<"key: "<<it1->first<<" value: "<<it1->second<<endl;
        it1++;
    }

    // iterator on map(ordered)
    map<string,int> ormap;
    ormap["abc"]=1;
    ormap["def"]=2;
    ormap["ghi"]=3;
    ormap["jkl"]=4;
    map<string,int>::iterator it2=ormap.begin();
    cout<<endl;
    while(it2!=ormap.end()){
        cout<<"key: "<<it2->first<<" value: "<<it2->second<<endl;
        it2++;
    }

    return 0;
}