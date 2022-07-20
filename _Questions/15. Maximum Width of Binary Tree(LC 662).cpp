// Problem Link:
// Leetcode 662. Maximum Width of Binary Tree: https://leetcode.com/problems/maximum-width-of-binary-tree/



// BFS Approach: => TC: O(n), SC: O(n)

    using ll = long long;
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        
        ll ans = 0;
        queue<pair<TreeNode*, ll>> q;
        q.push({root, 0});
        while(q.empty() == false){
            ll sz = q.size(), row_min = q.front().second;
            ll first, last;
            for(int i = 0; i<sz; i++){
                ll curr = q.front().second - row_min;
                TreeNode *node = q.front().first;
                q.pop();
                if(i == 0) first = curr;
                if(i == sz-1) last = curr;
                if(node->left)
                    q.push({node->left, 2*curr + 1});
                if(node->right)
                    q.push({node->right, 2*curr + 2});
            }
            ans = max(ans, last-first+1);
        }
        return ans;
        
    }
