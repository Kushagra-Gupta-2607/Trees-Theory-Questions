// Problem Link:
// https://www.interviewbit.com/problems/path-to-given-node/


  bool path(TreeNode* root, int target, vector<int>& ans){
      if(root == NULL) return 0;
    
      ans.push_back(root->val);
    
      if(root->val == target) return true;
      if(path(root->left, target, ans) || path(root->right, target, ans)) return true;
    
      ans.pop_back();
      return false;
  }

  vector<int> Solution::solve(TreeNode* A, int B) {
      vector<int> ans;
      bool x = path(A, B, ans);
      return ans;
  }
