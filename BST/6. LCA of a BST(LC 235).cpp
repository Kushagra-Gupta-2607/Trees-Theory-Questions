// Problem Link:
// Leetcode 235. Lowest Common Ancestor of a Binary Search Tree: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/



    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) return NULL;
        if(root->val<p->val && root->val<q->val) return lowestCommonAncestor(root->right, p, q);
        if(root->val>p->val && root->val>q->val) return lowestCommonAncestor(root->left, p, q);
        return root;
    }
