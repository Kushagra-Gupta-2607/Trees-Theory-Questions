// Problem Link: 
// Leetcode 103. Binary Tree Zigzag Level Order Traversal: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/


// Level Order Traversal - Queue -> TC: O(nodes), SC: O(nodes)
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL) return {};
        
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        int l_to_r = 1;

        while(q.empty() == false){
            int sz = q.size();
            vector<int> row(sz);
            
            for(int idx = 0; idx<sz; idx++){
                TreeNode *curr = q.front();
                q.pop();
                if(l_to_r) row[idx] = curr->val;
                else row[sz-1-idx] = curr->val;
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            
            ans.emplace_back(row);
            l_to_r^=1;
        }
        return ans;
    }
