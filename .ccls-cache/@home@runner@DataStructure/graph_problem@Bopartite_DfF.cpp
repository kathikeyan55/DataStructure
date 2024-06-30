#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
bool dfs(vector<vector<int>> graph, int col , vector<int>& color, int node){
    color[node] = col;
    for(auto it : graph[node]){
        if(color[it] == -1){
            if(!dfs(graph, 1-col, color, it)) return false;
        }else if(col == color[it]) return false;
    }
    return true;
}
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V, -1);
        for(int i = 0 ; i < V ; i++){
            if(color[i] == -1){
               if( !dfs(graph , 0 , color , i))return false;
            }
        }
        return true;
    }
};