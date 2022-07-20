


// Easy Case: where only the property has to be satisfied, adding 1's any no. of times
void childrenSumProperty(TreeNode* root){
    if(root == NULL) return;
    
    int child = 0;
    if(root->left) child+=root->left->val;
    if(root->right) child+=root->right->val;
    
    if(child<root->val){
        if(root->left) root->left->val = root->val;
        if(root->right) root->right->val = root->val;
    }
    else root->val = child;
    
    childrenSumProperty(root->left);
    childrenSumProperty(root->right);
    
    child = 0;
    if(root->left) child+=root->left->val;
    if(root->right) child+=root->right->val;
    if(root->left || root->right) root->val = child;
    
}


// Difficult Case: satisfy the property with adding minimum no. of 1's.

// To be continued ...
