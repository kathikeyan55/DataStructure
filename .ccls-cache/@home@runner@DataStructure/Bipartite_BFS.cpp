#include<bits/stdc++.h>
using namespace std;

class Solution {

private:
bool check(vector<vector<int>>& graph , vector<int> &color , int start) {
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto it : graph[node]){
            if(color[it] == -1){
                color[it] = 1 - color[node];
                q.push(it);
            }else if(color[it] == color[node]){
                return false;
            }
        }
    }
    return true;
}
public:
    bool isBipartite(vector<vector<int>>& graph) {
       
        vector<int> color(graph.size(), -1);
        // The issue is that you are not checking for disconnected components. 
        // You are only checking for bipartiteness starting from node 0.
        // You need to check for every node in the graph whether it is part of a bipartite graph or not
        for(int i = 0 ; i < graph.size() ; i++){
            if(color[i] == -1){
                color[i] = 0; // You can assign any color to start with
                if(!check(graph, color , i)){
                    return false;
                }
            }
        }
        return true;
    }
};