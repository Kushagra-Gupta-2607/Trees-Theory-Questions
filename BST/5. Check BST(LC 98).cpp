// Problem Link:
// Leetcode 98. Validate Binary Search Tree: https://leetcode.com/problems/validate-binary-search-tree/



    bool isValidBST(TreeNode* root, long long mn = LLONG_MIN, long long mx = LLONG_MAX) {
        if(root == NULL) return true;
        if(root->val<=mn || root->val>=mx) return false;
        return isValidBST(root->left, mn, root->val) && isValidBST(root->right, root->val, mx); 
    }
