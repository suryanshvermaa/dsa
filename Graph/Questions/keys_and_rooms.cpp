#include<iostream>
#include<vector>
#include<unordered_set>
#include<queue>
using namespace std;
unordered_set<int> visited;
bool isCanVisit(vector<vector<int>> &rooms){
    visited.clear();
    queue<int> qu;
    visited.insert(0);
    qu.push(0);
    while(!qu.empty()){
        int currRoom=qu.front();
        qu.pop();
        for(auto neighbourRoom:rooms[currRoom]){
            if(!visited.count(neighbourRoom)){
                visited.insert(neighbourRoom);
                qu.push(neighbourRoom);
            }
        }
    }
    return visited.size()==rooms.size();
}
int main(){
    vector<vector<int>> rooms({{1,3},{3,0,1},{2},{0}});
    cout<<(isCanVisit(rooms)?"yes we can visit all rooms!!!":"No we cant visit all rooms!!!")<<endl;
    return 0;
}