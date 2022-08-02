// Problem Link:
// Leetcode 297. Serialize and Deserialize Binary Tree: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL) return "#,";
        queue<TreeNode*> q;
        q.push(root);
        string s;
        while(q.empty() == false){
            TreeNode *curr = q.front();
            q.pop();
            if(curr == NULL){
                s+="#,";
                continue;
            }
            s+=to_string(curr->val) + ',';
            q.push(curr->left);
            q.push(curr->right);
        }
        // cout << s << endl;
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        // Using stringstream
        if(data == "#,") return NULL;
        
        stringstream s(data);
        string str;
        getline(s, str, ',');
        
        TreeNode *root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        
        while(q.empty() == false){
            TreeNode *curr = q.front();
            q.pop();
            
            getline(s, str, ',');
            if(str == "#")
                curr->left == NULL;
            else{
                curr->left = new TreeNode(stoi(str));
                q.push(curr->left);
            }
            
            getline(s, str, ',');
            if(str == "#")
                curr->right == NULL;
            else{
                curr->right = new TreeNode(stoi(str));
                q.push(curr->right);
            }
        }
        
        return root;
        
        
        // queue<pair<TreeNode*, int>> q;
        // int idx = 0, n = data.size(), num;
        // TreeNode *root = NULL;
        // while(idx<n){
        //     string k;
        //     while(data[idx] != ','){
        //         k+=data[idx];
        //         idx++;
        //     }
        //     idx++;
        //     if(k != "#") num = stoi(k);
        //     if(q.empty()){
        //         if(k == "#"){
        //             root = NULL;
        //             break;
        //         }
        //         root = new TreeNode(num);
        //         q.push({root, 0});
        //     }
        //     else{
        //         TreeNode *temp = q.front().first;
        //         int &flag = q.front().second;
        //         if(flag == 0){
        //             flag++;
        //             if(k == "#"){
        //                 temp->left = NULL;
        //                 continue;
        //             }
        //             temp->left = new TreeNode(num);
        //             q.push({temp->left, 0});
        //         }
        //         else{
        //             q.pop();
        //             if(k == "#"){
        //                 temp->right = NULL;
        //                 continue;
        //             }
        //             temp->right = new TreeNode(num);
        //             q.push({temp->right, 0});
        //         }
        //     }
        // }
        // return root;
    }
};
