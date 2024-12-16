#include<iostream>
#include<vector>
#include <stdlib.h>
using namespace std;
//leetcode question concept builder
void flood_fill(int sR,int sC,int newColor,int initialColor,vector<vector<int>> &arr){
    // if same color as initial color then we dont want to perform because already painted
    if(newColor==initialColor) return;

    int totalRows=arr.size();
    int totalColms=arr[0].size();
    if(sR<0 || sC<0 || sR>=totalRows||sC>=totalColms) return;
    if(arr[sR][sC]!=initialColor) return;
    arr[sR][sC]=newColor;

    //traverse all directions
    flood_fill(sR,sC-1,newColor,initialColor,arr);
    flood_fill(sR,sC+1,newColor,initialColor,arr);
    flood_fill(sR-1,sC,newColor,initialColor,arr);
    flood_fill(sR+1,sC,newColor,initialColor,arr);
}
int main(){
    vector<vector<int>> inputArr({{1,1,1},{1,1,0},{1,0,1}});
    flood_fill(0,0,2,1,inputArr);
    for(auto colors:inputArr){
        for(auto color:colors){
            cout<<color<<" ";
        }
        cout<<endl;
    }
    return 0;
}