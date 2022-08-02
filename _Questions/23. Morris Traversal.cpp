// InOrder

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == NULL) return {};
        vector<int> inorder;
        while(root != NULL){
            if(root->left == NULL){
                inorder.push_back(root->val);
                root = root->right;
            }
            else{
                TreeNode *prev = root->left;
                while(prev->right != NULL && prev->right != root){
                    prev = prev->right;
                }
                
                if(prev->right == NULL){
                    prev->right = root;
                    root = root->left;
                }
                else{
                    prev->right = NULL;
                    inorder.push_back(root->val);
                    root = root->right;
                }
            }
        }
        return inorder;
    }
};

// PreOrder
class Solution {
public:
    
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == NULL) return {};
        vector<int> preorder;
        while(root != NULL){
            if(root->left == NULL){
                preorder.push_back(root->val);
                root = root->right;
            }
            else{
                TreeNode *prev = root->left;
                while(prev->right != NULL && prev->right != root){
                    prev = prev->right;
                }
                
                if(prev->right == NULL){
                    prev->right = root;
                    preorder.push_back(root->val);
                    root = root->left;
                }
                else{
                    prev->right = NULL;
                    root = root->right;
                }
            }
        }
        return preorder;
    }
};
