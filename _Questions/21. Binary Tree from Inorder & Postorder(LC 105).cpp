// Problem Link:
// Leetcode 106. Construct Binary Tree from Inorder and Postorder Traversal: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

// TC => O(n), SC => O(n);

class Solution {
public:
    TreeNode *tree(unordered_map<int, int>& inMap, vector<int>& post, int startp, int endp, int starti, int endi){
        if(startp>endp) return NULL;
        if(startp == endp) return new TreeNode(post[startp]);
        
        int pos = inMap[post[endp]], left_gap = pos-starti;
        
        TreeNode *root = new TreeNode(post[endp]);
        root->left = tree(inMap, post, startp, startp + left_gap-1, starti, pos-1);
        root->right = tree(inMap, post, startp + left_gap, endp-1, pos+1, endi);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        unordered_map<int, int> inMap;
        for(int i = 0; i<n; i++){
            inMap[inorder[i]] = i;
        }
        return tree(inMap, postorder, 0, n-1, 0, n-1);
    }
};
