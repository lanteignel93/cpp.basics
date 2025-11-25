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

# Average of Levels in Binary Tree
## Description 
You are given an image represented by an `m x n` grid of integers `image`, where `image[i][j]` represents the pixel value of the image. You are also given three integers `sr`, `sc`, and `color`. Your task is to perform a **flood fill** on the image starting from the pixel `image[sr][sc]`.

To perform a **flood fill**:

1. Begin with the starting pixel and change its color to `color`.
2. Perform the same process for each pixel that is **directly adjacent** (pixels that share a side with the original pixel, either horizontally or vertically) and shares the **same color** as the starting pixel.
3. Keep **repeating** this process by checking neighboring pixels of the _updated_ pixels and modifying their color if it matches the original color of the starting pixel.
4. The process **stops** when there are **no more** adjacent pixels of the original color to update.

Return the **modified** image after performing the flood fill.

**Example 1:**
```
**Input:** image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2

**Output:** [[2,2,2],[2,2,0],[2,0,1]]
```

**Explanation:**

![](https://assets.leetcode.com/uploads/2021/06/01/flood1-grid.jpg)

From the center of the image with position `(sr, sc) = (1, 1)` (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.

Note the bottom corner is **not** colored 2, because it is not horizontally or vertically connected to the starting pixel.

**Example 2:**

```
**Input:** image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, color = 0

**Output:** [[0,0,0],[0,0,0]]
```

**Explanation:**

The starting pixel is already colored with 0, which is the same as the target color. Therefore, no changes are made to the image.

**Constraints:**

- `m == image.length`
- `n == image[i].length`
- `1 <= m, n <= 50`
- `0 <= image[i][j], color < 216`
- `0 <= sr < m`
- `0 <= sc < n`
## Code 
```cpp
class Solution {
  public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc,
                                  int color) {
        int ROWS = static_cast<int>(image.size());
        int COLS = static_cast<int>(image[0].size());

        std::queue<std::pair<int, int>> q;
        int startColor = image[sr][sc];
        q.push({sr, sc});
        image[sr][sc] = color;

        int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        std::vector<std::vector<int>> visit(ROWS, std::vector<int>(COLS, 0));

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            for (auto d : directions) {
                int nr = r + d[0];
                int nc = c + d[1];
                if (nr >= 0 && nr < ROWS && nc >= 0 && nc < COLS &&
                    image[nr][nc] == startColor && visit[nr][nc] != 1) {
                    image[nr][nc] = color;
                    visit[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
        return image;
    }
};
```