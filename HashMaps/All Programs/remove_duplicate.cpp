#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;


vector<int> remove_duplicate(int *arr,int size){
    unordered_map<int,bool> map;
    vector<int> output;

    for(int i=0;i<size;i++){
        int key=arr[i];
        if(map.count(key)==0){
            map[key]=true;
            output.push_back(key);
        }
    }
    return output;
}

int main(){
    int n;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    vector<int> v=remove_duplicate(arr,n);

    for(int i=0;i<v.size();i++){
        cout<<v.at(i)<<" ";
    }

    return 0;
}