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

# Word Search
## Description 
Given an `m x n` grid of characters `board` and a string `word`, return `true` _if_ `word` _exists in the grid_.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

**Example 1:**

![](https://assets.leetcode.com/uploads/2020/11/04/word2.jpg)
```
**Input:** board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
**Output:** true
```

**Example 2:**

![](https://assets.leetcode.com/uploads/2020/11/04/word-1.jpg)

```
**Input:** board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
**Output:** true
```

**Example 3:**

![](https://assets.leetcode.com/uploads/2020/10/15/word3.jpg)

```
**Input:** board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
**Output:** false
```

**Constraints:**

- `m == board.length`
- `n = board[i].length`
- `1 <= m, n <= 6`
- `1 <= word.length <= 15`
- `board` and `word` consists of only lowercase and uppercase English letters.
## Code 
```cpp
class Solution {
  private:
  public:
    bool dfs(std::vector<std::vector<char>> &board, int r, int c, int currSum,
             std::string &word) {
        int ROWS = static_cast<int>(board.size());
        int COLS = static_cast<int>(board[0].size());
        int wordLength = static_cast<int>(word.length());
        if (currSum == wordLength) {
            return true;
        }
        if (r < 0 || r >= ROWS || c < 0 || c >= COLS ||
            board[r][c] != word[currSum]) {
            return false;
        }

        char ogChar = board[r][c];
        board[r][c] = '#';
        currSum++;
        bool found = (dfs(board, r + 1, c, currSum, word) ||
                      dfs(board, r - 1, c, currSum, word) ||
                      dfs(board, r, c + 1, currSum, word) ||
                      dfs(board, r, c - 1, currSum, word));
        board[r][c] = ogChar;

        return found;
    }

    bool exist(vector<vector<char>> &board, string word) {
        int ROWS = static_cast<int>(board.size());
        int COLS = static_cast<int>(board[0].size());
        char startingChar = word[0];

        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                if (board[r][c] == startingChar) {
                    if (dfs(board, r, c, 0, word)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};

```