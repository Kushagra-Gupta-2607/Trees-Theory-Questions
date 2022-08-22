// Problem Link:
// Leetcode 230. Kth Smallest Element in a BST: https://leetcode.com/problems/kth-smallest-element-in-a-bst/



// Recursive Inorder

    void check(TreeNode* root, int& ans, int& k){
        if(root == NULL) return;
        check(root->left, ans, k);
        if(--k == 0) ans = root->val;
        check(root->right, ans, k);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;
        check(root, ans, k);
        return ans;
    }
    // (reverse root->right, root->left for kth largest)


// Iterative Inorder

  int kthSmallest(TreeNode* root, int k){
        stack<TreeNode*> st;
        while(1){
            while(root != NULL){
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            if(k-- == 1) return root->val;
            root = root->right;
        }
    }
