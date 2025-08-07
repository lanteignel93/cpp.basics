/*
You are given a 2-D matrix grid. Each cell can have one of three possible
values:

    0 representing an empty cell
    1 representing a fresh fruit
    2 representing a rotten fruit

Every minute, if a fresh fruit is horizontally or vertically adjacent to a
rotten fruit, then the fresh fruit also becomes rotten.

Return the minimum number of minutes that must elapse until there are zero fresh
fruits remaining. If this state is impossible within the grid, return -1.
*/
class Solution {
  public:
    int orangesRotting(std::vector<std::vector<int>> &grid) {
        int ROWS = grid.size(), COLS = grid[0].size();

        std::queue<std::pair<int, int>> q;
        int fresh = 0;
        int time = 0;

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (grid[r][c] == 1) {
                    fresh++;
                }
                if (grid[r][c] == 2) {
                    q.push({r, c});
                }
            }
        }

        std::vector<std::pair<int, int>> directions = {
            {0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while (fresh > 0 && !q.empty()) {
            int length = q.size();
            for (int i = 0; i < length; ++i) {
                auto curr = q.front();
                q.pop();
                int r = curr.first;
                int c = curr.second;

                for (const auto &dir : directions) {
                    int row = r + dir.first;
                    int col = c + dir.second;

                    if (row >= 0 && col >= 0 && row < ROWS && col < COLS &&
                        grid[row][col] == 1) {
                        grid[row][col] = 2;
                        q.push({row, col});
                        fresh--;
                    }
                }
            }
            time++;
        }
        return fresh == 0 ? time : -1;
    }
};
