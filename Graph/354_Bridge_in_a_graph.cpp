/*
Given an undirected graph of V vertices and E edges. Your task is to 
find all the bridges in the given undirected graph. A bridge in any 
graph is defined as an edge which, when removed, makes the graph 
disconnected (or more precisely, increases the number of connected 
components in the graph).

Link : https://www.geeksforgeeks.org/bridge-in-a-graph/
Link : https://www.codingninjas.com/codestudio/problems/bridges-in-graph_893026
Constraints :
    1 <= T <= 50
    1 <= V <= 10 ^ 3
    V-1 <= E <= 3 * 10^3
    0 <= a, b < V

    Time Limit: 1 sec
*/


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, int &timer, vector<int> &disc, vector<int> &low, 
            vector<vector<int>> &result, unordered_map<int, list<int>> &adjList,
            unordered_map<int, bool> &visited){
    
    visited[node] = true;
    disc[node] = low[node] = timer++;
    
    for(auto neighbour : adjList[node]){
        if(neighbour == parent){
            continue;
        }
        if(!visited[neighbour]){
            dfs(neighbour, node, timer, disc, low, result, adjList, visited);
            // updating the lowestTime, assuming back edges was found, 
            // and there may be a shortes path. Hence we need to update the low value
            low[node] = min(low[node], low[neighbour]);
            
            //check edge is bridge or not
            if(low[neighbour] > disc[node]){ //it means back edge is not found. This will be true when node is discoverd first and then neighbour is discovered.
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(neighbour);
                result.push_back(ans);
            }
        }else{
            // back edge : visiting the already visited node
            low[node] = min(low[node], disc[neighbour]); // disc[neighbour] : already visited node
         }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    unordered_map<int, list<int>> adjList;

    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
        
    int timer = 0;
    int parent = -1;
    vector<int> discvrdTime(v, -1);
    vector<int> lowstTime(v, -1);
    unordered_map<int, bool> visited;
    
    //dfs
    vector<vector<int>> result;
    for(int i=0; i<v; i++){
        if(!visited[i]){
            dfs(i, parent, timer, discvrdTime, lowstTime, result, adjList, visited);
        }
    }
    return result;
}