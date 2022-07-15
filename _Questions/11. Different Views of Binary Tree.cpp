/*
Demo Input:
[1, 2, 7, 3, null,41, 23, 43, 21, 99, null, 8, null, 4, 9, null, 5, 6, 10, 11]

                          1
                    2             7
              3           41            23
       43         21,99          8
  4          9,6        5,10,11


Demo Output:

Right View  : 1 7 23 8 11
Left View   : 1 2 3 43 4 
Top View    : 4 43 3 2 1 7 23 
Bottom View : 4 43 6 99 11 8 23 

*/

// Right View of Binary Tree -> Leetcode Link: https://leetcode.com/problems/binary-tree-right-side-view/

    void recursion(TreeNode *root, vector<int> &ans, int level = 0){
        if(root==NULL) return ;
      
        if(ans.size() == level) ans.push_back(root->val);
        recursion(root->right, ans, level+1);
        recursion(root->left, ans, level+1);
    }

    vector<int> rightSideView(TreeNode *root) {
        vector<int> ans;
        recursion(root, ans);
      
        cout << "Right View: ";
        for(auto x: ans){
            cout << x << " "; 
        }
        cout << endl;
      
        return ans;
    }


// Left View of Binary Tree

    void recursion(TreeNode *root, vector<int> &ans, int level = 0){
        if(root==NULL) return ;
      
        if(ans.size() == level) ans.push_back(root->val);
        recursion(root->left, ans, level+1);
        recursion(root->right, ans, level+1);
    }

    vector<int> leftSideView(TreeNode *root) {
        vector<int> ans;
        recursion(root, ans);
      
        cout << "Left View: ";
        for(auto x: ans){
            cout << x << " "; 
        }
        cout << endl;
      
        return ans;
    }


// Top View of Binary Tree

    void top_view(TreeNode* root){
        if(root == NULL) return;

        map<int, int> mp;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while(q.empty() == false){
            TreeNode* curr = q.front().first;
            int col = q.front().second;
            q.pop();
            if(mp.count(col) == false) mp[col] = curr->val;
            if(curr->left) q.push({curr->left, col-1});
            if(curr->right) q.push({curr->right, col+1});        
        }

        cout << "Top View: ";
        for(auto x: mp){
            cout << x.second << " "; 
        }
        cout << endl;
    }


// Bottom View Of Binary Tree

    void bottom_view(TreeNode* root){
        if(root == NULL) return;

        map<int, int> mp;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while(q.empty() == false){
            TreeNode *curr = q.front().first;
            int col = q.front().second;
            q.pop();
            mp[col] = curr->val;
            if(curr->left) q.push({curr->left, col-1});
            if(curr->right) q.push({curr->right, col+1});
        }

        cout << "Bottom View: ";
        for(auto x: mp){
            cout << x.second << " "; 
        }
        cout << endl;
    }
