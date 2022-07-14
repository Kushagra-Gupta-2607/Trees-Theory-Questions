// Problem Link:
// Leetcode 545. Boundary of Binary Tree : https://leetcode.com/problems/boundary-of-binary-tree/

/*

Intuition->
    1. Left Boundary excluding leaf
    2. Leaf nodes
    3. Reverse Right Boundary excluding leaf
    
*/

    // Check if it's a leaf node
    bool isLeaf(TreeNode* root){
        if(root->left == NULL && root->right == NULL) return true;
        return false;
    }

    // Pre-Order Approach to insert in array
    void addLeftBoundary(TreeNode* root, vector<int>& ans){
        if(root == NULL || isLeaf(root)) return;
        ans.push_back(root->val);
        if(root->left) addLeftBoundary(root->left, ans);
        else addLeftBoundary(root->right, ans);
    }

    // Pre-Order Approach to insert the leaves in the array from left to right order
    void addLeaves(TreeNode* root, vector<int>& ans){
        if(root == NULL) return;
        if(isLeaf(root)) ans.push_back(root->val);
        addLeaves(root->left, ans);
        addLeaves(root->right, ans);
    }

    // Post-Order Approach to insert in array
    void addRightBoundary(TreeNode* root, vector<int>& ans){
        if(root == NULL || isLeaf(root)) return;
        if(root->right) addRightBoundary(root->right, ans);
        else addRightBoundary(root->left, ans);
        ans.push_back(root->val);
    }

    vector<int> printBoundary(TreeNode* root){
        if(root == NULL) return {};

        vector<int> ans;
        if(isLeaf(root) == false) ans.push_back(root->val);
        addLeftBoundary(root->left, ans);
        addLeaves(root, ans);
        addRightBoundary(root->right, ans);
        return ans;
    }
