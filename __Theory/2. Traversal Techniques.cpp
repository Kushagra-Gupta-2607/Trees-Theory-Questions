/*

Depth First Search:

    1. Inorder Traversal ( Left Root Right )
    
    2. Pre-Order Traversal ( Root Left Right )
    
    3. Pos-Order Traversal ( Left Root Right )
    
Breadth First Search:

    1. Level Order Traversal
    
*/

void inorder(Node* root){
      if(root == NULL) return;
  
      inorder(root->left);
      cout << root->val << " ";
      inorder(root->right);
}

void preorder(Node* root){
      if(root == NULL) return;
      
      cout << root->val << " ";
      preorder(root->left);
      preorder(root->right);
}

void postorder(Node* root){
      if(root == NULL) return;
  
      postorder(root->left);
      postorder(root->right);
      cout << root->val << " ";
}

void levelOrderTraversal(Node* root){
      if(root == NULL) return;
  
      queue<Node*> q;
      q.push(root);

      while(q.empty() == false){
          Node* curr = q.front();
          q.pop();
          if(curr->left) q.push(curr->left);
          if(curr->right) q.push(curr->right);
          cout << curr->val << " ";
      }
  
}

