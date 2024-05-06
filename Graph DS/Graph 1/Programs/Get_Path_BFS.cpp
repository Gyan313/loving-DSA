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


unordered_map<int,int> getPathHelper(int** graph,bool* visited,int v,int start,int end){
    queue<int> q;
    q.push(start);
    visited[start]=true;
    unordered_map<int,int> path;
    while(!q.empty()){
        int front=q.front();
        q.pop();
        if(front==end){
            visited[front]=true;
            return path;
        }
        for(int i=0;i<v;i++){
            if(graph[front][i]==1 && !visited[i]){
                q.push(i);
                path[i]=front;
                visited[i]=true;
            }
        }
    }
    
    path[-1]=-1;
    return path;
}

void getPath(int** graph,int v){
    bool* visited=new bool[v];
    for(int i=0;i<v;i++){
        visited[i]=false;
    }

    int start,end;
    cin>>start>>end;
    unordered_map<int,int> path=getPathHelper(graph,visited, v, start, end);

    if(path.count(-1)==0){
        int i=end;
        while(i!=start){
            cout<<i<<" ";
            i=path[i];
        }
        cout<<start;
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
 