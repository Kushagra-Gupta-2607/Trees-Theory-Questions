// Problem Link:
// Leetcode 100. Same Tree: https://leetcode.com/problems/same-tree/


// Recursive Approach

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL || q == NULL)
            return p == q;
        return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }

// Iterative Apprach (BFS, Queue)

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr || q == nullptr)
            return p == q;
        if(p->val != q->val) return false;
        
        queue<TreeNode*> que;
        que.push(p);
        que.push(q);
        while(!que.empty()){
            TreeNode* first = que.front();
            que.pop();
            TreeNode* second = que.front();
            que.pop();
            if(first == nullptr || second == nullptr){
                if(first == second) continue;
                return false;
            }
            if(first->val != second->val) return false;
            que.push(first->left);
            que.push(second->left);
            que.push(first->right);
            que.push(second->right);
        }
        return true;
    }
