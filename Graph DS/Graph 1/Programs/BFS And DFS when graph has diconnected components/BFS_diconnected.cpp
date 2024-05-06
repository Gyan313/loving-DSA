#include<iostream>
#include<queue>
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

void singleComponentBFS(int** graph,int n,int sv,bool* visited){    
    queue<int> q;
    q.push(sv);
    visited[sv]=true;
    while(!q.empty()){
        int front=q.front();
        q.pop();
        cout<<front<<" ";
        for(int i=0;i<n;i++){
            if(graph[front][i]==1){
                if(!visited[i]){
                    q.push(i);
                    visited[i]=true;
                }
            }
        }
    }
}

void print_graph(int** graph,int n){
    bool* visited=new bool[n];
    for(int i=0;i<n;i++){
        visited[i]=false;
    }

    for(int i=0;i<n;i++){
        if(!visited[i]){
            singleComponentBFS(graph,n,i,visited);
        }
    }

    delete [] visited;
}

int main(){
    int n,e;  // n=no. of vertices   & e=no. of edges 
    cin>>n>>e;
    int** graph=input_graph(n,e);

    // print graph using BFS traversal
    print_graph(graph,n);

    // Deleting the memory we allocated
    for(int i=0;i<n;i++){
        delete [] graph[i];
    }
    delete [] graph;

    return 0;
}