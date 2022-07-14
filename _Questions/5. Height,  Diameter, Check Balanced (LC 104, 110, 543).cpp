// Problems Link:
// Leetcode 104. Maximum Depth of Binary Tree : https://leetcode.com/problems/maximum-depth-of-binary-tree/
// Leetcode 110. Balanced Binary Tree         : https://leetcode.com/problems/balanced-binary-tree/
// Leetcode 543. Diameter of Binary Tree      : https://leetcode.com/problems/diameter-of-binary-tree/


// Maximum Depth (Height) of Binary Tree - TC: O(nodes), SC: O(height)

    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }


// Balanced Binary Tree - TC: O(nodes), SC: O(height)

    int check(TreeNode* root){
        if(root == NULL) return 0;
        
        int left_height = check(root->left);
        if(left_height == -1) return -1;
        
        int right_height = check(root->right);
        if(right_height == -1) return -1;
        
        return abs(left_height-right_height)>1 ? -1 : 1+max(left_height, right_height);
    }
    
    bool isBalanced(TreeNode* root) {
        return check(root) != -1;
    }


// Diameter of Binary Tree - TC: O(nodes), SC: O(height)

    int check(TreeNode* root, int& ans){
        if(root == NULL) return 0;
        
        int lh = check(root->left, ans);
        int rh = check(root->right, ans);
        ans = max(ans, lh+rh);
        
        return 1+max(lh, rh);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        int height = check(root, ans);
        return ans;
    }


