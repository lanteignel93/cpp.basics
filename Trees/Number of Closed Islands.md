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

# Number of Closed Islands
## Description 
Given a 2D `grid` consists of `0s` (land) and `1s` (water).  An _island_ is a maximal 4-directionally connected group of `0s` and a _closed island_ is an island **totally** (all left, top, right, bottom) surrounded by `1s.`

Return the number of _closed islands_.

**Example 1:**

![](https://assets.leetcode.com/uploads/2019/10/31/sample_3_1610.png)

**Input:** `grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]`
**Output:** 2
**Explanation:** 
Islands in gray are closed because they are completely surrounded by water (group of 1s).

**Example 2:**

![](https://assets.leetcode.com/uploads/2019/10/31/sample_4_1610.png)

**Input:** `grid = [[0,0,1,0,0],[0,1,0,1,0],[0,1,1,1,0]]`
**Output:** 1

**Example 3:**
```
**Input:** grid = [[1,1,1,1,1,1,1],
               [1,0,0,0,0,0,1],
               [1,0,1,1,1,0,1],
               [1,0,1,0,1,0,1],
               [1,0,1,1,1,0,1],
               [1,0,0,0,0,0,1],
               [1,1,1,1,1,1,1]]
```
**Output:** 2

**Constraints:**

- `1 <= grid.length, grid[0].length <= 100`
- `0 <= grid[i][j] <=1`
## Code 
```cpp
class Solution {
  private:
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

  public:
    void dfs(std::vector<std::vector<int>> &grid, int r, int c) {
        int ROWS = static_cast<int>(grid.size());
        int COLS = static_cast<int>(grid[0].size());

        if (r < 0 || r >= ROWS || c < 0 || c >= COLS || grid[r][c] == 1) {
            return;
        }
        grid[r][c] = 1;
        for (const auto &d : directions) {
            dfs(grid, r + d[0], c + d[1]);
        }
        return;
    }

    int closedIsland(vector<vector<int>> &grid) {
        int ROWS = static_cast<int>(grid.size());
        int COLS = static_cast<int>(grid[0].size());

        for (int c = 0; c < COLS; c++) {
            if (grid[0][c] == 0)
                dfs(grid, 0, c);
            if (grid[ROWS - 1][c] == 0)
                dfs(grid, ROWS - 1, c);
        }

        for (int r = 0; r < ROWS; r++) {
            if (grid[r][0] == 0)
                dfs(grid, r, 0);
            if (grid[r][COLS - 1] == 0)
                dfs(grid, r, COLS - 1);
        }

        int res = 0;

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (grid[r][c] == 0) {
                    dfs(grid, r, c);
                    res++;
                }
            }
        }
        return res;
    }
};

```