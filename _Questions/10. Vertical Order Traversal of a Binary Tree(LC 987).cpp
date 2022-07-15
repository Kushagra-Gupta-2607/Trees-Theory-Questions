// Problem Link:
// Leetcode 987. Vertical Order Traversal of a Binary Tree: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/

// Recursive Approach - 12 ms solution

    void check(TreeNode* root, vector<vector<int>>& curr, int col = 0, int row = 0){
        if(root == NULL) return;
        curr.push_back({col, row, root->val});
        check(root->left, curr, col-1, row+1);
        check(root->right, curr, col+1, row+1);
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root == NULL) return {};
        vector<vector<int>> ans, curr;
        check(root, curr);
        sort(curr.begin(), curr.end());
        int curr_idx = 0;
        ans.push_back({curr[0][2]});
        for(int idx = 1; idx<curr.size(); idx++){
            if(curr[idx][0] != curr[idx-1][0]){
                ans.emplace_back();
                curr_idx++;
            }
            ans[curr_idx].push_back(curr[idx][2]);
        }
        return ans;
    }


// Iterative Approach (Level Order Traversal) - 3ms solution

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root == NULL) return {};
        
        vector<vector<int>> ans, curr;
        queue<pair<pair<int, int>, TreeNode*>> q;
        q.push({{0, 0}, root});
        while(q.empty() == false){
            TreeNode *node = q.front().second;
            int col = q.front().first.first;
            int row = q.front().first.second;
            q.pop();
            
            curr.push_back({col, row, node->val});
            if(node->left) q.push({{col-1, row+1}, node->left});
            if(node->right) q.push({{col+1, row+1}, node->right});
        }
        
        sort(curr.begin(), curr.end());
        int curr_idx = 0;
        ans.push_back({curr[0][2]});
        for(int idx = 1; idx<curr.size(); idx++){
            if(curr[idx][0] != curr[idx-1][0]){
                ans.emplace_back();
                curr_idx++;
            }
            ans[curr_idx].push_back(curr[idx][2]);
        }
        return ans;
    }
