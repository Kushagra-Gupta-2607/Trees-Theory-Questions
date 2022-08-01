// Problem Link:
// Leetcode 105. Construct Binary Tree from Preorder and Inorder Traversal: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

// TC => O(n), SC => O(n);

class Solution {
public:
    TreeNode *tree(unordered_map<int, int>& inMap, vector<int>& pre, int startp, int endp, int starti, int endi){
        if(startp>endp) return NULL;
        if(startp == endp) return new TreeNode(pre[startp]);
        
        int pos = inMap[pre[startp]], left_gap = pos-starti;
        
        TreeNode *root = new TreeNode(pre[startp]);
        root->left = tree(inMap, pre, startp+1, startp + left_gap, starti, pos-1);
        root->right = tree(inMap, pre, startp + left_gap+1, endp, pos+1, endi);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        unordered_map<int, int> inMap;
        for(int i = 0; i<n; i++){
            inMap[inorder[i]] = i;
        }
        return tree(inMap, preorder, 0, n-1, 0, n-1);
    }
};
