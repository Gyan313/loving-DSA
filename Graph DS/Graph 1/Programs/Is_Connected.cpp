#include <iostream> 
#include<unordered_map> 
#include <queue>  
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

void isConnectedHelper(int** graph,bool* visited,int v,int sv){
    visited[sv]=true;
    for(int i=0;i<v;i++){
        if(graph[sv][i]==1 && !visited[i]){
            visited[i]=true;
            isConnectedHelper(graph,visited, v, i);
        }
    }
}

bool isConnected(int** graph,int v){
    bool* visited=new bool[v];
    for(int i=0;i<v;i++){
        visited[i]=false;
    }

    isConnectedHelper(graph,visited,v,0);

    for(int i=0;i<v;i++){
        if(!visited[i]){
            return false;
        }
    }
    return true;
}


int main() {
    // Write your code here
    int v,e;
    cin>>v>>e;
    int **graph=input_graph(v,e);

    string result=(isConnected(graph,v))?"true":"false";
    cout<<result;

    for(int i=0;i<v;i++){
        delete [] graph[i];
    }
    delete [] graph;
    return 0;
} 
 