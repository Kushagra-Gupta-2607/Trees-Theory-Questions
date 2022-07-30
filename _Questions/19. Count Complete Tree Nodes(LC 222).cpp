// Problem Link:
// Leetcode 222. Count Complete Tree Nodes: https://leetcode.com/problems/count-complete-tree-nodes/

    int findLeftHeight(TreeNode* root){
        if(root == NULL) return 0;
        return 1 + findLeftHeight(root->left);
    }
    
    int findRightHeight(TreeNode* root){
        if(root == NULL) return 0;
        return 1 + findRightHeight(root->right);
    }
    
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        
        int lh = findLeftHeight(root);
        int rh = findRightHeight(root);
        
        if(lh == rh) return (1<<lh)-1;
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

//     Another method => A single function approach
//     using pii = pair<int, int>;
    
//     pii check(TreeNode* root){
//         if(root == NULL) return {0, 0};
        
//         pii leftH = check(root->left);
//         pii rightH = check(root->right);
        
//         if(leftH.first == rightH.first && leftH.first != -1){
//             int count = pow(2, ++leftH.first) - 1;
//             return {leftH.first, count};
//         }
//         return {-1, leftH.second + rightH.second + 1};
//     }
    
//     int countNodes(TreeNode* root) {
//         return check(root).second;
//     }
