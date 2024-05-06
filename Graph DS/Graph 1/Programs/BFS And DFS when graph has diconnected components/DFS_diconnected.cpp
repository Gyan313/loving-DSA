#include<iostream>
using namespace std;

int** input_graph(int n,int e){

    int **graph=new int*[n];
    for(int i=0;i<n;i++){
        graph[i]=new int[n];
        for(int j=0;j<n;j++){
            graph[i][j]=0;
        }
    }

    for(int i=0;i<e;i++){
        int f,s;  // f=1st vertex & s=2nd vertex
        cin>>f>>s;
        graph[f][s]=1;
        graph[s][f]=1;
        // f and s vertecies connected with bidirectional edge
        // Yahan hum edges maang rahe user ki kin kin vertices ke beech me edge h.

    }

    return graph;
}

void selectedComponentDFS(int** graph,int n,int sv,bool* visited){
    cout<<sv<<endl;
    visited[sv]=true;    // sv --> starting vertex
    for(int i=0;i<n;i++){
        if(i==sv){
            continue;
        }
        if(graph[sv][i]==1){
            if(visited[i]){
                continue;
            }
            selectedComponentDFS(graph,n,i,visited);
        }
    }
}

void print_graph(int** graph,int n){
    bool* visited=new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }

    for(int i=0;i<n;i++){
        if(!visited[i]){ // check this visited here so that we can print connected components
            selectedComponentDFS(graph,n,i,visited);   
        }
    }

    delete [] visited;
}

int main(){
    int n,e;  // n=no. of vertices   & e=no. of edges 
    cin>>n>>e;
    int** graph=input_graph(n,e);

    // print graph using DFS traversal
    print_graph(graph,n);

    // Deleting the memory we allocated
    for(int i=0;i<n;i++){
        delete [] graph[i];
    }
    delete [] graph;
    return 0;
}