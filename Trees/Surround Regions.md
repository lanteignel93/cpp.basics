---
status: Done
difficulty: Medium
algo: DFS - Recursive
group:
  - Trees
isProblem: true
stars: 5
---
#dsa
[[_010 Computer Science MOC]]
[[DSA Map.canvas|DSA Learning Map]]
[[PG_ DSA|DSA MOC]]
[[PG_Depth First Search (DFS) - Recursive Problems]]

# Surrounded Regions
## Description 
You are given an `m x n` matrix `board` containing **letters** `'X'` and `'O'`, **capture regions** that are **surrounded**:

- **Connect**: A cell is connected to adjacent cells horizontally or vertically.
- **Region**: To form a region **connect every** `'O'` cell.
- **Surround**: The region is surrounded with `'X'` cells if you can **connect the region** with `'X'` cells and none of the region cells are on the edge of the `board`.

To capture a **surrounded region**, replace all `'O'`s with `'X'`s **in-place** within the original board. You do not need to return anything.

**Example 1:**
```
**Input:** board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]

**Output:** [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
```

**Explanation:**

![](https://assets.leetcode.com/uploads/2021/02/19/xogrid.jpg)

In the above diagram, the bottom region is not captured because it is on the edge of the board and cannot be surrounded.

**Example 2:**

```
**Input:** board = [["X"]]

**Output:** [["X"]]
```

**Constraints:**

- `m == board.length`
- `n == board[i].length`
- `1 <= m, n <= 200`
- `board[i][j]` is `'X'` or `'O'`.
## Code 
```cpp
class Solution {
  public:
    void dfs(std::vector<std::vector<char>> &board, int r, int c) {
        int ROWS = static_cast<int>(board.size());
        int COLS = static_cast<int>(board[0].size());

        if (r < 0 || r >= ROWS || c < 0 || c >= COLS || board[r][c] != 'O') {
            return;
        }
        board[r][c] = '#';
        dfs(board, r - 1, c);
        dfs(board, r + 1, c);
        dfs(board, r, c - 1);
        dfs(board, r, c + 1);
        return;
    }

    void solve(vector<vector<char>> &board) {
        int ROWS = static_cast<int>(board.size());
        int COLS = static_cast<int>(board[0].size());

        // Flip 'O' and connected 'O' on the vertical edges to '#'
        for (int r = 0; r < ROWS; r++) {
            if (board[r][0] == 'O') {
                dfs(board, r, 0);
            }
            if (board[r][COLS - 1] == 'O') {
                dfs(board, r, COLS - 1);
            }
        }
        // Flip 'O' and connected 'O' on the horizontal edges to '#'
        for (int c = 0; c < COLS; c++) {
            if (board[0][c] == 'O') {
                dfs(board, 0, c);
            }
            if (board[ROWS - 1][c] == 'O') {
                dfs(board, ROWS - 1, c);
            }
        }

        // Flip all 'O' that aren't from edges that were converted to '#'
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (board[r][c] == 'O')
                    board[r][c] = 'X';
                // Flip all '#' back to 'O'
                if (board[r][c] == '#')
                    board[r][c] = 'O';
            }
        }
    }
};
```