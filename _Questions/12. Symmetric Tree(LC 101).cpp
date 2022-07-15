// Problem Link:
// Leetcode 101. Symmetric Tree: https://leetcode.com/problems/symmetric-tree/

    bool check(TreeNode* leftSub, TreeNode* rightSub){
        if(leftSub == NULL || rightSub == NULL)
            return left == right;
        
        return leftSub->val == rightSub->val && check(leftSub->left, rightSub->right) && check(leftSub->right, rightSub->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        return check(root, root);
    }
