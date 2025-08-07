/*
You are given an m x n integer array grid. There is a robot initially located
at the top-left corner (i.e., grid[0][0]). The robot tries to move to the
bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either
down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the
robot takes cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the
bottom-right corner.

The testcases are generated so that the answer will be less than or equal to 2 *
(10^9).
*/
class Solution {
  public:
    int uniquePathsWithOBstacles(std::vector<std::vector<int>> &grid) {
        int M = grid.size(), N = grid[0].size();
        if (grid[0][0] == 1 || grid[M - 1][M - 1] == 1) {
            return 0;
        }
        std::vector::std::vector < int >> dp(M + 1, std::vector<int>(N + 1, 0));
        dp[M - 1][N - 1] = 1;

        for (int r = M - 1; r >= 0; r--) {
            for (int c = N - 1; c >= 0; c--) {
                if (grid[r][c] == 1) {
                    dp[r][c] = 0;
                } else {
                    dp[r][c] += dp[r + 1][c];
                    dp[r][c] += dp[r][c + 1];
                }
            }
        }
        return dp[0][0];
    }
};
