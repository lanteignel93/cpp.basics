---
status: Done
difficulty: Medium
algo: DFS - Recursive
group:
  - Trees
isProblem: true
stars: 3
---
#dsa
[[_010 Computer Science MOC]]
[[DSA Map.canvas|DSA Learning Map]]
[[PG_ DSA|DSA MOC]]
[[PG_Depth First Search (DFS) - Recursive Problems]]

# Find Elements in a Contaminated Binary Tree

## Description 
Given a binary tree with the following rules:

1. `root.val == 0`
2. For any `treeNode`:
    1. If `treeNode.val` has a value `x` and `treeNode.left != null`, then `treeNode.left.val == 2 * x + 1`
    2. If `treeNode.val` has a value `x` and `treeNode.right != null`, then `treeNode.right.val == 2 * x + 2`

Now the binary tree is contaminated, which means all `treeNode.val` have been changed to `-1`.

Implement the `FindElements` class:

- `FindElements(TreeNode* root)` Initializes the object with a contaminated binary tree and recovers it.
- `bool find(int target)` Returns `true` if the `target` value exists in the recovered binary tree.

**Example 1:**

![](https://assets.leetcode.com/uploads/2019/11/06/untitled-diagram-4-1.jpg)

**Input**
```
["FindElements","find","find"]
[[[-1,null,-1]],[1],[2]]
```
**Output**
```
[null,false,true]
```
**Explanation**
```
FindElements findElements = new FindElements([-1,null,-1]); 
findElements.find(1); // return False 
findElements.find(2); // return True 
```

**Example 2:**

![](https://assets.leetcode.com/uploads/2019/11/06/untitled-diagram-4.jpg)

**Input**
```
["FindElements","find","find","find"]
[[[-1,-1,-1,-1,-1]],[1],[3],[5]]
```
**Output**
```
[null,true,true,false]
```
**Explanation**
```
FindElements findElements = new FindElements([-1,-1,-1,-1,-1]);
findElements.find(1); // return True
findElements.find(3); // return True
findElements.find(5); // return False
```

**Example 3:**

![](https://assets.leetcode.com/uploads/2019/11/07/untitled-diagram-4-1-1.jpg)

**Input**
```
["FindElements","find","find","find","find"]
[[[-1,null,-1,-1,null,-1]],[2],[3],[4],[5]]
```
**Output**
```
[null,true,false,false,true]
```
**Explanation**
```
FindElements findElements = new FindElements([-1,null,-1,-1,null,-1]);
findElements.find(2); // return True
findElements.find(3); // return False
findElements.find(4); // return False
findElements.find(5); // return True
```

**Constraints:**

- `TreeNode.val == -1`
- The height of the binary tree is less than or equal to `20`
- The total number of nodes is between `[1, 104]`
- Total calls of `find()` is between `[1, 104]`
- `0 <= target <= 106`
## Code 
```cpp
class FindElements {
  private:
    TreeNode *_root = nullptr;
    std::unordered_set<int> _valid_values;

  public:
    FindElements(TreeNode *root) {
        _root = root;
        _root->val = 0;
        _valid_values.insert(0);
        fixTree(_root);
    }

    void fixTree(TreeNode *root) {
        if (root == nullptr)
            return;

        if (root->left != nullptr) {
            int left_val = 2 * root->val + 1;
            root->left->val = left_val;
            _valid_values.insert(left_val);
        }
        if (root->right != nullptr) {
            int right_val = 2 * root->val + 2;
            root->right->val = right_val;
            _valid_values.insert(right_val);
        }

        fixTree(root->left);
        fixTree(root->right);
    }

    bool find(int target) { return _valid_values.count(target); }
};

```