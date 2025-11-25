---
status: Done
difficulty: Medium
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

# Daily Temperatures
## Description 
You are given an array of integers `temperatures` where `temperatures[i]` represents the daily temperatures on the `ith` day.

Return an array `result` where `result[i]` is the number of days after the `ith` day before a warmer temperature appears on a future day. If there is no day in the future where a warmer temperature will appear for the `ith` day, set `result[i]` to `0` instead.

**Example 1:**

```java
Input: temperatures = [30,38,30,36,35,40,28]

Output: [1,4,1,2,1,0,0]
```

**Example 2:**

```java
Input: temperatures = [22,21,20]

Output: [0,0,0]
```

**Constraints:**

- `1 <= temperatures.length <= 1000`.
- `1 <= temperatures[i] <= 100`
## Code 
```cpp
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::vector<int> res(temperatures.size(), 0); 
        std::stack<std::pair<int, int>> _stack; 

        for (int i = 0; i < temperatures.size(); ++i) {
            
            if (_stack.empty()) {
                _stack.push({temperatures[i], i}); 
                continue; 
            }

            while ((!_stack.empty()) &&(temperatures[i] > _stack.top().first)) {
                res[_stack.top().second] = i - _stack.top().second;
                _stack.pop();
            }
            _stack.push({temperatures[i], i}); 
        }
        return res;

    }
};
```