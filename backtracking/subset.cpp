/*
Given an array nums of unique integers, return all possible subsets of nums.

The solution set must not contain duplicate subsets. You may return the solution
in any order.

Example 1:

Input: nums = [1,2,3]

Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Example 2:

Input: nums = [7]

Output: [[],[7]]

Constraints:

    1 <= nums.length <= 10
    -10 <= nums[i] <= 10

*/
class Solution {
  public:
    void dfs(const vector<int> &nums, int i, std::vector<int> &subset,
             std::vector<std::vector<int>> &res) {
        if (i >= nums.size()) {
            for (int num : subset) {
                std::cout << num << " ";
            }
            std::cout << "\n";
            res.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        dfs(nums, i + 1, subset, res);
        std::cout << "pop_back()" << "\n";
        subset.pop_back();
        dfs(nums, i + 1, subset, res);
    }

    vector<vector<int>> subsets(vector<int> &nums) {
        std::vector<std::vector<int>> res;
        std::vector<int> subset;
        dfs(nums, 0, subset, res);
        return res;
    }
};
