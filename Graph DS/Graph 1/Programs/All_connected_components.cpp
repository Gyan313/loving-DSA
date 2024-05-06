#include <iostream> 
#include <queue> 
#include <algorithm> 
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

vector<int> allConnectedComponentsHelper(int** graph,bool* visited,int v,int sv){
    queue<int> q;
    q.push(sv);
    visited[sv]=true;
    vector<int> child;
    child.push_back(sv);
    while(!q.empty()){
        int front=q.front();
        q.pop();
        for(int i=0;i<v;i++){
            if(graph[front][i]==1 && !visited[i]){
                q.push(i);
                visited[i]=true;
                child.push_back(i);
            }
        }
    }

    return child;
}

void allConnectedComponents(int** graph,int v){
    bool* visited=new bool[v];
    for(int i=0;i<v;i++){
        visited[i]=false;
    }

    vector<vector<int>> graphs;
    for(int i=0;i<v;i++){
        if(!visited[i]){
            graphs.push_back(allConnectedComponentsHelper(graph,visited,v,i));
        }
    }

    delete [] visited;

    for(int i=0;i<graphs.size();i++){
        sort(graphs.at(i).begin(), graphs.at(i).end());
        for(int j=0;j<graphs.at(i).size();j++){
            cout<<graphs.at(i).at(j)<<" ";
        }
        cout<<endl;
    }

}


int main() {
    // Write your code here
    int v,e;
    cin>>v>>e;
    int **graph=input_graph(v,e);

    allConnectedComponents(graph,v);

    for(int i=0;i<v;i++){
        delete [] graph[i];
    }
    delete [] graph;
    return 0;
} 
 