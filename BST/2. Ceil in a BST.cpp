// Problem Link:
// Codestudio https://www.codingninjas.com/codestudio/problems/ceil-from-bst_920464



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
