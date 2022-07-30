// Problem Link:
// Leetcode 863. All Nodes Distance K in Binary Tree: https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

/*

Intuition->
    1. Store Parents
    2. Make a visited set to store all the nodes we have gone through to avoid accessing same nodes
    3. call lef, right and parent of the current node starting from target node till k == 0 or root == NULL
    
*/


class Solution {
public:
    using mtt = unordered_map<TreeNode*, TreeNode*>;
    using stt = unordered_set<TreeNode*>;
  
//     // BFS Approach    
//     void assign(TreeNode* root, mtt& parent){
//         if(root == NULL) return;
//         queue<TreeNode*> q;
//         q.push(root);
//         while(q.empty() == false){
//             TreeNode *curr = q.front();
//             q.pop();
//             if(curr->left){
//                 parent[curr->left] = curr;
//                 q.push(curr->left);
//             }
//             if(curr->right){
//                 parent[curr->right] = curr;
//                 q.push(curr->right);
//             }
//         }
//     }
    
//     void check(TreeNode *root, vector<int>& ans, mtt& parent, stt& vis, int k){
//         if(root == NULL) return;
//         queue<pair<TreeNode*, int>> q;
//         q.push({root, k});
//         while(q.empty() == false){
//             TreeNode *curr = q.front().first;
//             int place = q.front().second;
//             q.pop();
//             if(vis.count(curr)) continue;
//             vis.insert(curr);
//             if(place == 0) ans.push_back(curr->val);
//             else{
//                 if(curr->left) q.push({curr->left, place-1});
//                 if(curr->right) q.push({curr->right, place-1});
//                 if(parent.count(curr)) q.push({parent[curr], place-1});
//             }
//         }
//     }
    
    // DFS Approach
    void assign(TreeNode* root, mtt& parent){
        if(root == NULL) return;
        if(root->left) parent[root->left] = root;
        if(root->right) parent[root->right] = root;
        assign(root->left, parent);
        assign(root->right, parent);
    }
    
    void check(TreeNode *root, vector<int>& ans, mtt& parent, stt& vis, int k){
        if(root == NULL || vis.count(root)) return;
        if(k == 0){
            ans.push_back(root->val);
            return;
        }
        vis.insert(root);
        check(root->left, ans, parent, vis, k-1);
        check(root->right, ans, parent, vis, k-1);
        if(parent.count(root)) check(parent[root], ans, parent, vis, k-1);
        
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        mtt parent;
        stt vis;
        assign(root, parent);
        vector<int> ans;
        check(target, ans, parent, vis, k);
        return ans;
    }
};
