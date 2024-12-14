#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
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

bool any_path(int src,int dest){
    if(src==dest) return true;
    visited.insert(src);
    for(auto neighbour:graph[src]){
        if(!visited.count(neighbour)){
            bool ans= any_path(neighbour,dest);
            if(ans) return true;
        }
    }
    return false;
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
    int s,d;
    cin>>s,d;
    cout<<any_path(s,d)<<endl;
    return 0;
}