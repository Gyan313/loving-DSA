#include <iostream> 
#include <vector> 
using namespace std;

int** input_graph(int v,int e){
    int** graph=new int*[v];
    for(int i=0;i<v;i++){
        graph[i]=new int[v];
        for(int j=0;j<v;j++ ){
            graph[i][j]=0;
        }
    }
     
    for(int i=0;i<e;i++){
        int f,s;
        cin>>f>>s;
        graph[f][s]=1;
        graph[s][f]=1;
    }

    return graph;
}


bool getPathHelper(int** graph,bool* visited,vector<int>* path,int v,int start,int end){
    if(start==end){
        path->push_back(start);
        visited[start]=true;
        return true;
    }
    path->push_back(start);
    visited[start]=true;
    for(int i=0;i<v;i++){
        if(graph[start][i]==1 && !visited[i]){
            if(getPathHelper(graph,visited,path,v,i,end)){
                return true;
            }
        }
    }
    return false;
}

void getPath(int** graph,int v){
    bool* visited=new bool[v];
    for(int i=0;i<v;i++){
        visited[i]=false;
    }

    int start,end;
    cin>>start>>end;
    vector<int>* path=new vector<int>();

    if(getPathHelper(graph, visited,path, v, start, end)){
        for(int i=path->size()-1;i>=0;i--){
            cout<<path->at(i)<<" ";
        }
        delete path;
    }
    else{
        return;
    }
    
    delete [] visited;
}

int main() {
    // Write your code here
    int v,e;
    cin>>v>>e;
    int **graph=input_graph(v,e);

    getPath(graph,v);

    for(int i=0;i<v;i++){
        delete [] graph[i];
    }
    delete [] graph;
    return 0;
} 
