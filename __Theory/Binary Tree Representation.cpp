struct Node{
    int val;
    struct Node *left, *right;

    Node(int val){
        this->val = val;
        this->left = this->right = nullptr;
    }
};

int main(){

    struct Node* root = new Node(0);
    root->left = new Node(1);
    root->right = new Node(2);

    return 0;
}
