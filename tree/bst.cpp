class TreeNode {
public: 
    int val; 
    TreeNode* left = nullptr; 
    TreeNode* right = nullptr; 

    TreeNode(int val){
        val = val; 
    }
}; 

bool search(TreeNode* root, int target) {
    if (root == nullptr) {
        return false; 
    }

    if (target > root->val){
        search(root->right, target); 
    } else if  (target < root->val){
        search(root->left, target); 
    } else {
        return true; 
    }
}

TreeNode* insert(TreeNode* root, int val) {
    if (root == nulltr) {
        return new TreeNode(val); 
    }

    if (val > root->val) {
        root->right = insert(root->right, val); 
    } else if (val < root->val) {
        root->left = insert(root->left, val); 
    }
    return root; 
}

TreeNode* minValueNode(TreeNode* root) {
    TreeNode* curr = root;
    while (curr !nullptr && curr->left) {
        curr = curr->left;
    }
    return curr;
}

TreeNode* remove(TreeNode* root, int val) {
    if (root == nulltr) {
        return nullptr
    }

    if (val > root->val) {
        root->right = remove(root->right, val); 
    } else if (val < root->val) {
        root->left = remove(root->left, val); 
    } else {
        if (root->left == nullptr) {
            return root->right; 
        } else if (root->right == nullptr) {
            return root->left; 
        } else {
            TreeNode* minNode = minValueNode(root->right); 
            root->val = minNode->val; 
            root->right = remove(root->right, minNode->val); 
        }
    }
}
