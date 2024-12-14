#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
#include<queue>
using namespace std;

vector<list<int>> graph;
unordered_set<int> visited;
int v; //no. of vertices
void add_edge(int src,int dest,bool bi_dir = true){
    graph[src].push_back(dest);
    if(bi_dir){
        graph[dest].push_back(src);
    }
}
void sortest_paths(int v,vector<int> &sortest_path_array){
    sortest_path_array[v]=0;
    queue<int> qu;
    qu.push(v);
    visited.insert(v);
    while(!qu.empty()){
        auto current=qu.front();
        qu.pop();
        for(auto neigbour:graph[current]){
            if(!visited.count(neigbour)){
                sortest_path_array[neigbour]=sortest_path_array[current]+1;
                visited.insert(neigbour);
                qu.push(neigbour);
            }
    }
    }
}


int main(){
    visited.clear();
    cin>>v;
    graph.resize(v,list<int> ());
    int e;
    cin>>e;
    while(e--){
        int s,d;
        cin>>s>>d;
        add_edge(s,d);
    }
    int vertex;
    cin>>vertex;
    vector<int> sortest_paths_array(v);
    sortest_paths(vertex,sortest_paths_array);
    for(int i=0;i<sortest_paths_array.size();i++){
        cout<<i<<"->"<<sortest_paths_array[i]<<endl;
    }

    return 0;
}