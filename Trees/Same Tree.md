---
status: Done
difficulty: Easy
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

# Same Tree
## Description 
Given the roots of two binary trees `p` and `q`, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

**Example 1:**

![](https://assets.leetcode.com/uploads/2020/12/20/ex1.jpg)
```
**Input:** p = [1,2,3], q = [1,2,3]
**Output:** true
```

**Example 2:**

![](https://assets.leetcode.com/uploads/2020/12/20/ex2.jpg)

```
**Input:** p = [1,2], q = [1,null,2]
**Output:** false
```

**Example 3:**

![](https://assets.leetcode.com/uploads/2020/12/20/ex3.jpg)

```
**Input:** p = [1,2,1], q = [1,1,2]
**Output:** false
```

**Constraints:**

- The number of nodes in both trees is in the range `[0, 100]`.
- `-104 <= Node.val <= 104`
## Code 
```cpp
class Solution {
  public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        std::queue<TreeNode *> lq, rq;

        if (!q && !p)
            return true;
        if (!q || !p || q->val != p->val)
            return false;

        lq.push(p);
        rq.push(q);

        while (!lq.empty() && !rq.empty()) {
            TreeNode *ln = lq.front();
            lq.pop();
            TreeNode *rn = rq.front();
            rq.pop();
            if (!ln && !rn)
                continue;
            if (!ln || !rn || ln->val != rn->val)
                return false;
            lq.push(ln->left);
            lq.push(ln->right);
            rq.push(rn->left);
            rq.push(rn->right);
        }
        return true;
    }
};

```
