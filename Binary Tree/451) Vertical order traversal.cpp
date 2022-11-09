/*
Veritcal Traversal of Binary Tree.
Link : https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1?ref=gcse

Example 1:
    Input:
           1
         /   \
       2       3
     /   \   /   \
   4      5 6      7
              \      \
               8      9           
    Output: 
    4 2 1 5 6 3 8 7 9 

Example 2:
    Input:
       1
    /    \
   2       3
 /    \      \
4      5      6
    Output: 4 2 1 5 3 6


Constraints:
    1 <= Number of nodes <= 3*10^4

    Expected Time Complexity: O(N)
    Expected Auxiliary Space: O(N)
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

vector<int> verticalOrder(Node *root)
{  //   horiz   vert         nodes
    map<int, map<int, vector<int>>> nodes;
    vector<int> ans;
    queue<pair<Node*, pair<int, int>>> q; // node, horizontal_dist, vertical_depth
    
    if(root == NULL){
        return ans;
    }
    
    q.push(make_pair(root, make_pair(0,0)));
    while(!q.empty()){
        pair<Node*, pair<int, int>> temp = q.front();
        q.pop();
        
        Node* frontNode = temp.first;
        int hd = temp.second.first;//horizontal_distance
        int level = temp.second.second; // vertical_depth
        
        nodes[hd][level].push_back(frontNode->data);
        
        if(frontNode->left){
            q.push(make_pair(frontNode->left, make_pair(hd-1, level+1)));
        }
        if(frontNode->right){
            q.push(make_pair(frontNode->right, make_pair(hd+1, level+1)));
        }
    }
    
    for(auto i : nodes){ // horizontal key_value pair, i = {vertical_depths}
        for(auto j : i.second){ // veritcal key_value pair, j = {particular_vertical_depth : vector}
            for(auto k : j.second){ // items inside the vector, k = vector values
                ans.push_back(k);
            }
        }
    }
    return ans;
}