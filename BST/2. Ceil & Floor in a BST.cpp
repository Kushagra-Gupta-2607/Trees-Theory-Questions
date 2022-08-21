// Problem Link:
// Codestudio 
// https://www.codingninjas.com/codestudio/problems/ceil-from-bst_920464
// https://www.codingninjas.com/codestudio/problems/floor-from-bst_920457


// Ceil in a BST
void check(BinaryTreeNode<int>* root, int& ans, int x){
    if(root == NULL) return;
    if(root->data>=x){
        ans = min(ans, root->data);
        check(root->left, ans, x);
    }
    else check(root->right, ans, x);
}

int findCeil(BinaryTreeNode<int> *node, int x){
    // Write your code here.
    int ans = 1e9;
    check(node, ans, x);
    return ans == 1e9 ? -1 : ans;
}


// Floor in a BST
void check(TreeNode<int>* root, int& ans, int& x){
    if(root == NULL) return;
    if(root->val<=x){
        ans = root->val;
        check(root->right, ans, x);
    }
    else check(root->left, ans, x);
}

int floorInBST(TreeNode<int> * root, int X)
{
    // Write your code here.
    int ans = -1;
    check(root, ans, X);
    return ans;
}
