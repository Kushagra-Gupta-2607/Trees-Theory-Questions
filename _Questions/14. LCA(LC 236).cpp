// Problem Link:
// Leetcode 236. Lowest Common Ancestor of a Binary Tree: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

// TC: O(n)
// SC: O(n)

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q) return root;
        
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        
        if(left != NULL && right != NULL) return root;
        if(left) return left;
        return right;
    }
