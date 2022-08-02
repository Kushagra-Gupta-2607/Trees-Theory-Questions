// Problem Link:
// Leetcode 114. Flatten Binary Tree to Linked List: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

// Method-1: Recursion (Reverse PreOrder)
class Solution {
public:
    TreeNode *prev = NULL;
    
    void flatten(TreeNode *root){
        if(root == NULL) return;
        
        flatten(root->right);
        flatten(root->left);
        
        root->right = prev;
        root->left = NULL;
        prev = root;
    }
};



// Method-2: Stack
class Solution {
public:
    void flatten(TreeNode *root){
        if(root == NULL) return;
        
        stack<TreeNode*> st;
        st.push(root);
        
        while(st.empty() == false){
            TreeNode *curr = st.top();
            st.pop();
            
            if(curr->right) st.push(curr->right);
            if(curr->left) st.push(curr->left);
            if(st.empty() == false) curr->right = st.top();
            
            curr->left = NULL;
        }
    }
};


// Method-3: Morris Traversal (0 ms , 100% fast) ( TC => O(n), SC => O(1) )
class Solution {
public:
    void flatten(TreeNode *root){
        if(root == NULL) return;
        
        TreeNode *curr = root;
        while(curr){
            if(curr->left != NULL){
                TreeNode *prev = curr->left;
                while(prev->right != NULL) prev = prev->right;
                
                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }
};
