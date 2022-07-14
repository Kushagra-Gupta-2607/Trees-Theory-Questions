/*
Demo Input : 1 2 5 3 4 6 7

│       ┌── 7
│   ┌── 5
│   │   └── 6
└── 1
    │   ┌── 4
    └── 2
        └── 3
*/

/*
Demo Output:

Preorder  :   1 2 3 4 5 6 7 
Inorder   :   3 2 4 1 6 5 7 
Postorder :   3 4 2 6 7 5 1 

*/

void allTraversals(TreeNode* root){
    if(root == NULL) return;
  
    vector<int> preorder, inorder, postorder;
    stack<pair<TreeNode*, int>> st;
    st.push({root, 1});
  
    while(st.empty() == false){
        TreeNode *curr = st.top().first;
        int& idx = st.top().second;
        if(idx == 1){
            preorder.push_back(curr->val);
            if(curr->left) st.push({curr->left, 1});
            idx++;
        }
        else if(idx == 2){
            inorder.push_back(curr->val);
            if(curr->right) st.push({curr->right, 1});
            idx++;
        }
        else{
            postorder.push_back(curr->val);
            st.pop();
        }
    }
    cout << "Preorder: ";
    for(int x: preorder) cout << x << " ";
    cout << endl;
    
    cout << "Inorder: ";
    for(int x: inorder) cout << x << " ";
    cout << endl;
    
    cout << "Postorder: ";
    for(int x: postorder) cout << x << " ";
    cout << endl;
}
