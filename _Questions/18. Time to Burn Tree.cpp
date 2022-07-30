// Problem Link:
// CodeStudio Time to Burn Tree: https://www.codingninjas.com/codestudio/problem-details/time-to-burn-tree_630563

#include<bits/stdc++.h>

using mtt = unordered_map<BinaryTreeNode<int>*, BinaryTreeNode<int>*>;
using stt = unordered_set<BinaryTreeNode<int>*>;

// // BFS Approach
//     BinaryTreeNode<int>* assign(BinaryTreeNode<int>* root, mtt& parent, int& start){
//         if(root == NULL) return NULL;
//         queue<BinaryTreeNode<int>*> q;
//         q.push(root);
//         BinaryTreeNode<int>* target = NULL;
//         while(q.empty() == false){
//             BinaryTreeNode<int> *curr = q.front();
//             q.pop();
//             if(curr->data == start) target = curr;
//             if(curr->left){
//                 parent[curr->left] = curr;
//                 q.push(curr->left);
//             }
//             if(curr->right){
//                 parent[curr->right] = curr;
//                 q.push(curr->right);
//             }
//         }
//         return target;
//     }

// int check(BinaryTreeNode<int>* root, mtt& parent, stt& vis){
//     if(root == NULL) return -1;
//     queue<BinaryTreeNode<int>*> q;
//     int ans = -1, flag = 0;
//     q.push(root);
//     while(q.empty() == false){
//         int sz = q.size();
//         while(sz--){
//             BinaryTreeNode<int>* curr = q.front();
//             q.pop();
//             if(vis.count(curr)) continue;
//             vis.insert(curr);
//             if(curr->left) q.push(curr->left);
//             if(curr->right) q.push(curr->right);
//             if(parent.count(curr)) q.push(parent[curr]), flag = 1; 
//             // flag is used so as to make sure to decrease the ans by -1 if we encounter a queue which is filled by all the visited members
//         }
//         ans++;
//     }
//     return ans-flag;
// }

// DFS Approach
BinaryTreeNode<int>* assign(BinaryTreeNode<int>* root, mtt& parent, int start){
        if(root == NULL) return root;
        if(root->left) parent[root->left] = root;
        if(root->right) parent[root->right] = root;
        BinaryTreeNode<int>* left = assign(root->left, parent, start);
        BinaryTreeNode<int>* right = assign(root->right, parent, start);
        return root->data == start ? root : (left == NULL ? right : left);
}

int check(BinaryTreeNode<int>* root, mtt& parent, stt& vis){
    if(root == NULL || vis.count(root)) return -1;
    vis.insert(root);
    int left = 1 + check(root->left, parent, vis);
    int right = 1 + check(root->right, parent, vis), up = INT_MIN;
    if(parent.count(root)) up = 1 + check(parent[root], parent, vis);
    return max({left, right, up});
}

int timeToBurnTree(BinaryTreeNode<int>* root, int start)
{
    mtt parent;
    stt vis;
    BinaryTreeNode<int>* target = assign(root, parent, start);
    return check(target, parent, vis);
    // Write your code here
}
