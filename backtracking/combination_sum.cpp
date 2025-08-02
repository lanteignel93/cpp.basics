/*
You are given an array of distinct integers nums and a target integer target.
Your task is to return a list of all unique combinations of nums where the
chosen numbers sum to target.

The same number may be chosen from nums an unlimited number of times. Two
combinations are the same if the frequency of each of the chosen numbers is the
same, otherwise they are different.

You may return the combinations in any order and the order of the numbers in
each combination can be in any order.

Example 1:

Input:
nums = [2,5,6,9]
target = 9

Output: [[2,2,5],[9]]

Explanation:
2 + 2 + 5 = 9. We use 2 twice, and 5 once.
9 = 9. We use 9 once.

Example 2:

Input:
nums = [3,4,5]
target = 16

Output: [[3,3,3,3,4],[3,3,5,5],[4,4,4,4],[3,4,4,5]]

*/
class Solution {
  private:
    std::vector<std::vector<int>> res;

  public:
    void backtrack(const std::vector<int> &nums, int target,
                   std::vector<int> &cur, int i) {
        if (target == 0) {
            res.push_back(cur);
            return;
        }
        if (target < 0 || i >= nums.size()) {
            return;
        }
        cur.push_back(nums[i]);
        backtrack(nums, target - nums[i], cur, i);
        cur.pop_back();
        backtrack(nums, target, cur, i + 1);
    }
    vector<vector<int>> combinationSum(vector<int> &nums, int target) {
        std::vector<int> cur;
        backtrack(nums, target, cur, 0);
        return res;
    }
};
