---
status: Done
difficulty: Medium
algo: DFS - Recursive
group:
  - Trees
isProblem: true
stars: 4
---
#dsa
[[_010 Computer Science MOC]]
[[DSA Map.canvas|DSA Learning Map]]
[[PG_ DSA|DSA MOC]]
[[PG_Depth First Search (DFS) - Recursive Problems]]

# Number of Enclaves
## Description 
Given the `root` node of a binary tree, your task is to create a string representation of the tree following a specific set of formatting rules. The representation should be based on a preorder traversal of the binary tree and must adhere to the following guidelines:

- **Node Representation**: Each node in the tree should be represented by its integer value.
    
- **Parentheses for Children**: If a node has at least one child (either left or right), its children should be represented inside parentheses. Specifically:
    
    - If a node has a left child, the value of the left child should be enclosed in parentheses immediately following the node's value.
    - If a node has a right child,You are given an `m x n` binary matrix `grid`, where `0` represents a sea cell and `1` represents a land cell.

A **move** consists of walking from one land cell to another adjacent (**4-directionally**) land cell or walking off the boundary of the `grid`.

Return _the number of land cells in_ `grid` _for which we cannot walk off the boundary of the grid in any number of **moves**_.

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/02/18/enclaves1.jpg)
```
**Input:** grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
**Output:** 3
**Explanation:** There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.
```

**Example 2:**

![](https://assets.leetcode.com/uploads/2021/02/18/enclaves2.jpg)

```
**Input:** grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
**Output:** 0
**Explanation:** All 1s are either on the boundary or can reach the boundary.
```

**Constraints:**

- `m == grid.length`
- `n == grid[i].length`
- `1 <= m, n <= 500`
- `grid[i][j]` is either `0` or `1`.
## Code 
```cpp
class Solution {
  private:
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

  public:
    void dfs(std::vector<std::vector<int>> &grid, int r, int c) {
        int ROWS = static_cast<int>(grid.size());
        int COLS = static_cast<int>(grid[0].size());

        if (r < 0 || r >= ROWS || c < 0 || c >= COLS || grid[r][c] != 1) {
            return;
        }

        grid[r][c] = 2;

        for (const auto &d : directions) {
            int dr = d[0], dc = d[1];
            dfs(grid, r + dr, c + dc);
        }
        return;
    }

    int numEnclaves(vector<vector<int>> &grid) {
        int ROWS = static_cast<int>(grid.size());
        int COLS = static_cast<int>(grid[0].size());

        for (int r = 0; r < ROWS; r++) {
            if (grid[r][0] == 1) {
                dfs(grid, r, 0);
            }
            if (grid[r][COLS - 1] == 1) {
                dfs(grid, r, COLS - 1);
            }
        }

        for (int c = 0; c < COLS; c++) {
            if (grid[0][c] == 1) {
                dfs(grid, 0, c);
            }
            if (grid[ROWS - 1][c] == 1) {
                dfs(grid, ROWS - 1, c);
            }
        }

        int res = 0;
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (grid[r][c] == 1) {
                    res++;
                }
            }
        }

        return res;
    }
};

```