---
status: Done
difficulty: Hard
algo: Stacks
group:
  - Stacks & Queues
isProblem: true
stars: 4
---
#dsa
[[_010 Computer Science MOC]]
[[DSA Map.canvas|DSA Learning Map]]
[[PG_ DSA|DSA MOC]]
[[PG_Stacks_Problems]]

# Largest Rectangle in Histogram 
## Description 
You are given an array of integers `heights` where `heights[i]` represents the height of a bar. The width of each bar is `1`.

Return the area of the largest rectangle that can be formed among the bars.

Note: This chart is known as a [histogram](https://en.wikipedia.org/wiki/Histogram).

**Example 1:**

```java
Input: heights = [7,1,7,2,2,4]

Output: 8
```

**Example 2:**

```java
Input: heights = [1,3,7]

Output: 7
```

**Constraints:**

- `1 <= heights.length <= 1000`.
- `0 <= heights[i] <= 1000`
## Code 
```cpp
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = static_cast<int>(heights.size());
        int res { 0 }; 
        std::stack<std::pair<int, int>> _stack; 

        for (int i = 0; i < n; ++i) {
            int start = i;
            int h = heights[i]; 
            while (!_stack.empty() && _stack.top().second > h) {
                auto [index, height] = _stack.top(); _stack.pop(); 
                res = std::max(res, height * (i - index)); 
                start = index; 
            }
            _stack.push({start, h}); 
        }
        while (!_stack.empty()) {
            auto [index, height] = _stack.top(); _stack.pop(); 
            res = std::max(res, height * (n - index)); 
        }

        return res;

    }
};


```