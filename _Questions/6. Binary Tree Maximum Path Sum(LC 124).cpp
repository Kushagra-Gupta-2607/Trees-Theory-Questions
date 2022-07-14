// Problem Link:
// Leetcode 124. Binary Tree Maximum Path Sum: https://leetcode.com/problems/binary-tree-maximum-path-sum/

    int check(TreeNode* root, int& ans){
        if(root == NULL) return 0;
        
        int left_sum = max(0, check(root->left, ans));    // Either return a positive sum from left else do not consider
        int right_sum = max(0, check(root->right, ans));  // Either return a positive sum from right else do not consider
        
        ans = max(ans, left_sum + right_sum + root->val); // check max from the current diameter(diameter only takes the left and right sum only when they're positive
        return root->val + max(left_sum, right_sum);      // return the maximum possible sum which might be possible either from left path or the right path.
    }
    
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        int height = check(root, ans);
        return ans;
    }
