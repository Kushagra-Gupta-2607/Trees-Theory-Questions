// Problem Link:
// Leetcode 98. Validate Binary Search Tree: https://leetcode.com/problems/validate-binary-search-tree/



    bool isValidBST(TreeNode* root, long long mn = LLONG_MIN, long long mx = LLONG_MAX) {
        if(root == NULL) return true;
        
        bool x = isValidBST(root->left, mn, root->val);
        bool y = isValidBST(root->right, root->val, mx);
        
        return x && y && root->val>mn && root->val<mx;
        
    }
