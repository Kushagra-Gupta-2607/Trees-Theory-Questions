// Recursive Approach

    void preorder(TreeNode* root, vector<int>& ans){
        if(root == NULL) return;
        
        ans.push_back(root->val);
        preorder(root->left, ans);
        preorder(root->right, ans);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(root, ans);
        return ans;
    }


// Iterative Approach - Using Stacks

    vector<int> preorderTraversal(TreeNode* root) {
        if(root == NULL) return {};
        
        vector<int> ans;
        stack<TreeNode*> st;
        st.push(root);
        
        while(st.empty() == false){
            TreeNode *curr = st.top();
            st.pop();
            // First right child is considered because we would have to remove the top element of the stack and thus left child would be on top
            if(curr->right != NULL) st.push(curr->right);
            if(curr->left != NULL) st.push(curr->left);
            ans.push_back(curr->val);
        }
        
        return ans;
    }
