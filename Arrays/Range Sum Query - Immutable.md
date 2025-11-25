---
status: Done
difficulty: Easy
algo: Prefix Sums
group:
  - Arrays
isProblem: true
stars: 4
---
#dsa
[[_010 Computer Science MOC]]
[[DSA Map.canvas|DSA Learning Map]]
[[PG_ DSA|DSA MOC]]
[[PG_Two-Pointers_Problems]]

# Range Sum Query - Immutable
## Description 
Given an integer array `nums`, handle multiple queries of the following type:

1. Calculate the **sum** of the elements of `nums` between indices `left` and `right` **inclusive** where `left <= right`.

Implement the `NumArray` class:

- `NumArray(int[] nums)` Initializes the object with the integer array `nums`.
- `int sumRange(int left, int right)` Returns the **sum** of the elements of `nums` between indices `left` and `right` **inclusive** (i.e. `nums[left] + nums[left + 1] + ... + nums[right]`).

**Example 1:**
```
**Input**
["NumArray", "sumRange", "sumRange", "sumRange"]
[[[-2, 0, 3, -5, 2, -1]], [0, 2], [2, 5], [0, 5]]
**Output**
[null, 1, -1, -3]

**Explanation**
NumArray numArray = new NumArray([-2, 0, 3, -5, 2, -1]);
numArray.sumRange(0, 2); // return (-2) + 0 + 3 = 1
numArray.sumRange(2, 5); // return 3 + (-5) + 2 + (-1) = -1
numArray.sumRange(0, 5); // return (-2) + 0 + 3 + (-5) + 2 + (-1) = -3
```

**Constraints:**

- `1 <= nums.length <= 104`
- `-105 <= nums[i] <= 105`
- `0 <= left <= right < nums.length`
- At most `104` calls will be made to `sumRange`.
## Code 
```cpp
class NumMatrix {
private:
    std::vector<std::vector<int>> prefix; 
public:
    NumMatrix(vector<vector<int>>& matrix) {
        for (auto const &row: matrix) {
            std::vector<int> prefix_ { 0 }; 
            for (int i = 0; i < row.size(); i++) {
                prefix_.push_back(row[i] + prefix_[i]); 
            }
            prefix.push_back(prefix_); 
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int res = 0; 
        for (int r = row1; r <= row2; r++) {
            res += prefix[r][col2 + 1] - prefix[r][col1];
        }
        return res;
    }
};
```
