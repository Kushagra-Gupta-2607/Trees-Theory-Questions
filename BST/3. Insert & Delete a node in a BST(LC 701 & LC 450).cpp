// Problem Link:
// Leetcode 701. Insert into a Binary Search Tree:  https://leetcode.com/problems/insert-into-a-binary-search-tree/
// Leetcode 450. Delete Node in a BST:              https://leetcode.com/problems/delete-node-in-a-bst/


// Insert
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL) return new TreeNode(val);
        if(root->val<=val) root->right = insertIntoBST(root->right, val);
        else root->left = insertIntoBST(root->left, val);
        return root;
    }


// Delete
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return root;
        if(root->val<key) root->right = deleteNode(root->right, key);
        else if(root->val>key) root->left = deleteNode(root->left, key);
        else{
            if(root->left == NULL && root->right == NULL) return NULL;
            if(root->left == NULL || root->right == NULL) return root->left ? root->left : root->right;
            TreeNode *temp = root->right;
            while(temp->left != NULL){
                temp = temp->left;
            }
            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);
        }
        return root;
    }
