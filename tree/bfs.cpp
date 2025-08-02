class TreeNode {
public:
    int val; 
    TreeNode* left = nullptr; 
    TreeNode* right = nullptr; 

    TreeNode(int val){
        val = val; 
    }
};

void bfs(TreeNode* root) {
    std::queue<TreeNode*> queue; 

    if (root != nullptr) {
        queue.push(root); 
    }

    int level = 0; 
    while (!queue.empty()) {
        std::cout << "Level: " << level << "\n"; 
        for (int i = 0; i < static_cast<int>(queue.size()); ++i){
            TreeNode* curr = queue.front(); 
            queue.pop(); 
            std::cout << curr->val << ' '; 
            if (curr->left != nullptr) {
                queue.push(curr->left); 
            }
            if (curr->right != nullptr) {
                queue.push(curr->right); 
            }
        }
        level++; 
        std::cout << "\n"; 
    }
}
