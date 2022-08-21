// Problem Link:
// Leetcode 700. Search in a Binary Search Tree: https://leetcode.com/problems/search-in-a-binary-search-tree/



// Recursion
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL || root->val == val) return root;
        if(root->val<val) return searchBST(root->right, val);
        return searchBST(root->left, val);
    }



// Iterative
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root && root->val != val) root = root->val<val ? root->right : root->left;
        return root;
    }
