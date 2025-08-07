/*
You are given an integer array nums where nums[i] represents the amount of money
the ith house has. The houses are arranged in a straight line, i.e. the ith
house is the neighbor of the (i-1)th and (i+1)th house.

You are planning to rob money from the houses, but you cannot rob two adjacent
houses because the security system will automatically alert the police if two
adjacent houses were both broken into.

Return the maximum amount of money you can rob without alerting the police.
*/
class Solution {
  public:
    int rob(std::vector<int> &nums) {
        if (nums.empty())
            return 0;
        if (nums.size() == 1)
            return nums[0];

        std::vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < nums.size(); i++) {
            dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
        }

        return dp[nums.size() - 1];
    }
};
