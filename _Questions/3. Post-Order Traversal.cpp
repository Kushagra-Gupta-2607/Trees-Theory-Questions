// Problem Link:
// https://leetcode.com/problems/binary-tree-postorder-traversal/

// Recursive Approach (6 ms solution)

    void postorder(TreeNode* root, vector<int>& ans){
        if(root == NULL) return;
        
        postorder(root->left, ans);
        postorder(root->right, ans);
        ans.push_back(root->val);
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorder(root, ans);
        return ans;
    }


// Iterative Approach - Using 2 Stacks (0 ms solution)

    vector<int> postorderTraversal(TreeNode* root) {
        if(root == NULL) return {};
        
        vector<int> ans;
        stack<TreeNode*> st1, st2;
        st1.push(root);
        while(st1.empty() == false){
            TreeNode *curr = st1.top();
            st1.pop();
            st2.push(curr);
            if(curr->left) st1.push(curr->left);
            if(curr->right) st1.push(curr->right);
        }
        while(st2.empty() == false){
            ans.push_back(st2.top()->val);
            st2.pop();
        }
        return ans;
    }

// Iterative Approach - Using 1 Stack (4 ms solution)

    vector<int> postorderTraversal(TreeNode* root) {
        if(root == NULL) return {};
        
        vector<int> ans;
        stack<TreeNode*> st;
        TreeNode* curr = root;
        while(curr != NULL || st.empty() == false){
            if(curr != NULL){
                st.push(curr);
                curr = curr->left;
            }
            else{
                TreeNode *temp = st.top()->right;
                if(temp == NULL){
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->val);
                    while(st.empty() == false && st.top()->right == temp){
                        temp = st.top();
                        st.pop();
                        ans.push_back(temp->val);
                    }
                }
                else curr = temp;
            }
        }
        
        return ans;
    }
