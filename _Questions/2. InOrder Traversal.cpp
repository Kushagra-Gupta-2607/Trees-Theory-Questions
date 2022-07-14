// Problem Link: 
// https://leetcode.com/problems/binary-tree-inorder-traversal/

// Recursive Approach

    void inorder(TreeNode* root, vector<int>& ans){
        if(root == NULL) return;
        
        inorder(root->left, ans);
        ans.push_back(root->val);
        inorder(root->right, ans);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }


// Iterative Approach - Using Stacks

    vector<int> inorderTraversal(TreeNode* root) {
        if(root == NULL) return {};
        
        stack<TreeNode*> st;
        vector<int> ans;
        TreeNode* curr = root;
        
        while(true){
            if(curr != NULL){
                st.push(curr);
                curr = curr->left;
            }
            else{
                if(st.empty()) break;
                curr = st.top();
                st.pop();
                ans.push_back(curr->val);
                curr = curr->right;
            }
        }
        return ans;
    }
