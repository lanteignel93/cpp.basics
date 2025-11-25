---
status: Done
difficulty: Hard
algo: Sliding Window
group:
  - Arrays
isProblem: true
stars: 5
---
#dsa
[[_010 Computer Science MOC]]
[[DSA Map.canvas|DSA Learning Map]]
[[PG_ DSA|DSA MOC]]
[[PG_Sliding_Window_Problems]]

# Sliding Window Maximum
## Description 
You are given an array of integers `nums` and an integer `k`. There is a sliding window of size `k` that starts at the left edge of the array. The window slides one position to the right until it reaches the right edge of the array.

Return a list that contains the maximum element in the window at each step.

**Example 1:**

```java
Input: nums = [1,2,1,0,4,2,6], k = 3

Output: [2,2,4,4,6]

Explanation: 
Window position            Max
---------------           -----
[1  2  1] 0  4  2  6        2
 1 [2  1  0] 4  2  6        2
 1  2 [1  0  4] 2  6        4
 1  2  1 [0  4  2] 6        4
 1  2  1  0 [4  2  6]       6
```

**Constraints:**

- `1 <= nums.length <= 1000`
- `-10,000 <= nums[i] <= 10,000`
- `1 <= k <= nums.length`
## Code 
```cpp
class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        int n = static_cast<int>(nums.size()); 
        std::vector<int> output(n - k + 1); 
        std::deque<int> q; 
        int l = 0, r = 0; 

        while (r < n) {
	        // Remove elements from the back smaller than the current number 
            while (!q.empty() && nums[q.back()] < nums[r]) {
                q.pop_back(); 
            }
            // Add element to the back of the queue 
            q.push_back(r); 

			// If left pointer is ahead of whatever is in the front of the queue, we are pass that window so remove it 
            if (l > q.front()) {
                q.pop_front(); 
            }

			// When the right pointer is far enough add whatever is in the front of the queue 
			// At where the left pointer is in output
            if ((r + 1) >= k) {
                output[l] = nums[q.front()]; 
                l++; 
            }
            r++; 
        }
        return output; 
    }
};
```
