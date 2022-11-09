/*
Given a binary tree. Find the inorder traversal of the tree without 
using recursion.
Link : https://practice.geeksforgeeks.org/problems/inorder-traversal-iterative/0/?fbclid=IwAR2_lL0T84DnciLyzMTQuVTMBOi82nTWNLuXjUgahnrtBgkphKiYk6xcyJU

Example 1
    Input:
              1
            /    \
           2      3
         /   \
        4     5
    Output: 4 2 5 1 3
    Explanation:
    Inorder traversal (Left->Root->Right) of 
    the tree is 4 2 5 1 3.

Example 2
    Input:
                 8
              /     \
             1       5
              \     /  \
               7   10   6
                \  /
                10 6
    Output: 1 7 10 8 6 10 5 6
    Explanation:
    Inorder traversal (Left->Root->Right) 
    of the tree is 1 7 10 8 6 10 5 6.


Constraints:
    1 <= Number of nodes <= 10^5
    1 <= Data of a node <= 10^5

    Expected time complexity: O(N)
    Expected auxiliary space: O(N)
*/

#include <bits/stdc++.h>
using namespace std;


struct Node {
    int data;
    Node* left;
    Node* right;
};

class Solution {
public:
    vector<int> inOrder(Node* root)
    {
        vector<int> ans;
        Node* curr = root;
        
        while(curr){
            if(curr->left == NULL){
                ans.push_back(curr->data);
                curr = curr->right;
            }else{
                Node* pred = curr->left; //predeccesor
                while(pred->right && pred->right != curr){
                    pred = pred->right;
                }
                if(pred->right == NULL){
                    pred->right = curr;
                    curr = curr->left;
                }else{
                    ans.push_back(curr->data);
                    pred->right = NULL;
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};