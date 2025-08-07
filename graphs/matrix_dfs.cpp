/*
You are given a matrix grid where grid[i] is either a 0 (representing water) or
1 (representing land).

An island is defined as a group of 1's connected horizontally or vertically. You
may assume all four edges of the grid are surrounded by water.

The area of an island is defined as the number of cells within the island.

Return the maximum area of an island in grid. If no island exists, return 0.
*/
class Solution {
  private:
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int res = 0;

  public:
    void dfs(std::vector<std::vector<int>> &grid, int r, int c, int &tmp) {
        // Check all boundary conditions plus if water cell (problem specific)
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() ||
            grid[r][c] == 0) {
            return;
        }
        // Convert the cell to water and increase count of cell on island
        grid[r][c] = 0;
        tmp++;
        // Navigate through all other directions
        for (int i = 0; i < 4; i++) {
            dfs(grid, r + directions[i][0], c + directions[i][1], tmp);
        }
    }

    int maxAreaOfIsland(std::vector<std::vector<int>> &grid) {
        int ROWS = grid.size(), COLS = grid[0].size();

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                // Run DFS if cell is not water
                if (grid[r][c] == 1) {
                    int tmp = 0;
                    dfs(grid, r, c, tmp);
                    if (tmp > res) {
                        res = tmp;
                    }
                }
            }
        }
        return res;
    }
}
