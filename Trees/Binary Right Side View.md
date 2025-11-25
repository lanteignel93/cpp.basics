---
status: Done
difficulty: Medium
algo: BFS
group:
  - Trees
isProblem: true
stars: 4
---
#dsa
[[_010 Computer Science MOC]]
[[DSA Map.canvas|DSA Learning Map]]
[[PG_ DSA|DSA MOC]]
[[PG_Breath First Search Problems]]

# Binary Right Side View
## Description 
You are given the `root` of a binary tree. Return only the values of the nodes that are visible from the right side of the tree, ordered from top to bottom.

**Example 1:**

![](https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/d348893a-8917-456c-9599-c405cfc4e000/public)

```java
Input: root = [1,2,3]

Output: [1,3]
```

**Example 2:**

![](https://imagedelivery.net/CLfkmk9Wzy8_9HRyug4EVA/c0b72861-13dc-42a6-030b-a4fb78139e00/public)

```java
Input: root = [1,2,3,4,5,6,7]

Output: [1,3,7]
```

**Constraints:**

- `0 <= number of nodes in the tree <= 100`
- `-100 <= Node.val <= 100`
## Code 
```cpp
class Solution {
public:
    std::vector<int> rightSideView(TreeNode* root) {
        std::vector<int> res; 
        if (!root) {
            return res; 
        }

        std::queue<TreeNode*> q; 
        q.push(root); 

        while (!q.empty()){
            int size = static_cast<int>(q.size()); 
            for (int i = 0; i < size; ++i) {
                TreeNode *currNode = q.front(); q.pop(); 
                if (i == size - 1) {
                    res.push_back(currNode->val);
                }
                if (currNode->left) {q.push(currNode->left);}
                if (currNode->right) {q.push(currNode->right);} 
            }
        }
        return res; 
    }
};
```