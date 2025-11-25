---
status: Done
difficulty: Easy
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

# Island Perimeter
## Description 
You are given `row x col` `grid` representing a map where `grid[i][j] = 1` represents land and `grid[i][j] = 0` represents water.

Grid cells are connected **horizontally/vertically** (not diagonally). The `grid` is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

**Example 1:**

![](https://assets.leetcode.com/uploads/2018/10/12/island.png)
```
**Input:** grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
**Output:** 16
**Explanation:** The perimeter is the 16 yellow stripes in the image above.

```
**Example 2:**

```
**Input:** grid = [[1]]
**Output:** 4
```

**Example 3:**

```
**Input:** grid = [[1,0]]
**Output:** 4

```
**Constraints:**

- `row == grid.length`
- `col == grid[i].length`
- `1 <= row, col <= 100`
- `grid[i][j]` is `0` or `1`.
- There is exactly one island in `grid`.
## Code 
```cpp
class Solution {
  public:
    int islandPerimeter(vector<vector<int>> &grid) {
        int ROWS = static_cast<int>(grid.size());
        int COLS = static_cast<int>(grid[0].size());

        if (ROWS == 1 && COLS == 1) {
            return 4;
        }

        int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        std::queue<std::pair<int, int>> q;

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    grid[i][j] = 2;
                    break;
                }
            }
        }
        int res = 0;
        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            int tmp{4};
            for (auto d : directions) {
                int nr = r + d[0];
                int nc = c + d[1];
                if (nr >= 0 && nr < ROWS && nc >= 0 && nc < COLS) {
                    if (grid[nr][nc] == 1 || grid[nr][nc] == 2) {
                        --tmp;
                    }

                    if (grid[nr][nc] == 1) {
                        q.push({nr, nc});
                        grid[nr][nc] = 2;
                    }
                }
            }
            res += tmp;
        }
        return res;
    }
};

```