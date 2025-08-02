class TreeNode {
public:
    int val; 
    TreeNode* left = nullptr; 
    TreeNode* right = nullptr; 

    TreeNode(int val){
        val = val; 
    }
};

void inorder(TreeNode* root) {
    if (root == nullptr) {
        return; 
    }
    inorder(root->left); 
    std::cout << root->val << "\n"; 
    inorder(root->right);
}

void preorder(TreeNode* root) {
    if (root == nullptr) {
        return; 
    }
    std::cout << root->val << "\n"; 
    inorder(root->left); 
    inorder(root->right);
}

void postorder(TreeNode* root) {
    if (root == nullptr) {
        return; 
    }
    inorder(root->left); 
    inorder(root->right);
    std::cout << root->val << "\n"; 
}

