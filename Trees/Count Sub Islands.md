---
status: Done
difficulty: Medium
algo: BFS
group:
  - Trees
isProblem: true
stars: 5
---
#dsa
[[_010 Computer Science MOC]]
[[DSA Map.canvas|DSA Learning Map]]
[[PG_ DSA|DSA MOC]]
[[PG_Breath First Search Problems]]

# Count Sub Islands
## Description 
You are given two `m x n` binary matrices `grid1` and `grid2` containing only `0`'s (representing water) and `1`'s (representing land). An **island** is a group of `1`'s connected **4-directionally** (horizontal or vertical). Any cells outside of the grid are considered water cells.

An island in `grid2` is considered a **sub-island** if there is an island in `grid1` that contains **all** the cells that make up **this** island in `grid2`.

Return the _**number** of islands in_ `grid2` _that are considered **sub-islands**_.

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/06/10/test1.png)

**Input:** `grid1 = [[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]], grid2 = [[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]]`
**Output:** `3`
**Explanation:** In the picture above, the grid on the left is grid1 and the grid on the right is grid2.
The 1s colored red in grid2 are those considered to be part of a sub-island. There are three sub-islands.

**Example 2:**

![](https://assets.leetcode.com/uploads/2021/06/03/testcasex2.png)

**Input:** `grid1 = [[1,0,1,0,1],[1,1,1,1,1],[0,0,0,0,0],[1,1,1,1,1],[1,0,1,0,1]], grid2 = [[0,0,0,0,0],[1,1,1,1,1],[0,1,0,1,0],[0,1,0,1,0],[1,0,0,0,1]]`
**Output:** `2
**Explanation:** In the picture above, the grid on the left is grid1 and the grid on the right is grid2.
The 1s colored red in grid2 are those considered to be part of a sub-island. There are two sub-islands.

**Constraints:**

- `m == grid1.length == grid2.length`
- `n == grid1[i].length == grid2[i].length`
- `1 <= m, n <= 500`
- `grid1[i][j]` and `grid2[i][j]` are either `0` or `1`.
## Code 
```cpp
class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        std::queue<std::pair<std::pair<int, int>, std::vector<std::pair<int, int>>>> islandStartPoint; 
        int ROWS = static_cast<int>(grid2.size()); 
        int COLS = static_cast<int>(grid2[0].size()); 

        int directions[4][2] = {{-1,0}, {1,0}, {0, 1}, {0,-1}}; 
        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                if (grid2[r][c] == 1) {
                    std::queue<std::pair<int, int>> q; 
                    std::vector<std::pair<int, int>> island; 
                    q.push({r, c}); 
                    while (!q.empty()) {
                        auto [r, c] = q.front(); q.pop(); 
                        island.push_back({r, c});
                        for (auto &[dr, dc] : directions) {
                            int nr = r + dr, nc = c + dc; 
                            if (nr >= 0 && nr < ROWS && nc >= 0 && nc < COLS && grid2[nr][nc] == 1) {
                                grid2[nr][nc] = 0; 
                                q.push({nr, nc}); 
                            }
                        }
                    }
                    islandStartPoint.push({{r,c}, island});
                }
            }
        }

        int islandCount = 0; 
        while (!islandStartPoint.empty()) {
            auto [startPoint, land_vector] = islandStartPoint.front(); islandStartPoint.pop(); 
            bool isSubIsland = true; 
            for (auto& [r, c] : land_vector) {
                if (grid1[r][c] != 1){
                    isSubIsland = false; 
                    break;
                }
            }
            if (isSubIsland) {
                ++islandCount; 
            }
        }
        return islandCount; 
    }
};
```