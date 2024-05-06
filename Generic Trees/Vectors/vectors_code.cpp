#include<iostream>
using namespace std;
#include<vector>

int main(){
    vector<int> v;
    vector<int>* v1=new vector<int>();

    v.push_back(10);
    v.push_back(12);
    v.push_back(14);

    cout<<v[0]<<endl;
    cout<<v[1]<<endl;
    cout<<v[2]<<endl;

    v.pop_back();
    // cout<<v[2]<<endl;
    cout<<v.at(2)<<endl;
    v[1]=0;
    cout<<v[1]<<endl;
    cout<<v.size()<<endl;
    return 0;
}