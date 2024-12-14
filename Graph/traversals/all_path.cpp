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
void all_path(int curr,int end,vector<int> &path,vector<vector<int>> &paths){
    path.push_back(curr);
    visited.insert(curr);
    if(curr==end) {
        paths.push_back(path);
        path.pop_back();
        visited.erase(curr);
        return;
    }
    for(auto neighbour:graph[curr]){
        if(!visited.count(neighbour)){
            all_path(neighbour,end,path,paths);
        }
    }
    path.pop_back();
    visited.erase(curr);
    return;
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
    int src,dest;
    cin>>src>>dest;
    vector<vector<int>> paths;
    vector<int> path;
    cout<<"paths from "<<src<<" to "<<dest<<":-"<<endl;
    all_path(src,dest,path,paths);
    for(auto p:paths){
        for(auto el:p){
            cout<<el<<"->";
        }
        cout<<endl;
    }

    return 0;
}