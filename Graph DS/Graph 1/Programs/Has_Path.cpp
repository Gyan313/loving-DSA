#include <iostream>
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

void hasPath(int** graph,bool* visited,int v,int f,int s){
    if(f==s){
        return;
    }
    visited[f]=true;
    for(int i=0;i<v;i++){
        if(graph[f][i]==1 && !visited[i]){
            visited[i]=true;
            hasPath(graph,visited,v,i,s);
        }
    }
}

int main() {
    // Write your code here
    int v,e;
    cin>>v>>e;
    int **graph=input_graph(v,e);
    bool *visited=new bool[v];
    for(int i=0;i<v;i++){
        visited[i]=false;
    }

    int f,s; // f=first vertex & s=second vertex
    cin>>f>>s;
    hasPath(graph,visited,v,f,s);  // here hasPath uses DFS traversal, you can use BFS traversal
    if(visited[s]){
        cout<<"true";
    }
    else{
        cout<<"false";
    }

    for(int i=0;i<v;i++){
        delete [] graph[i];
    }
    delete [] graph;
    delete [] visited;
    return 0;
}