---
status: Done
difficulty: Easy
algo: Sliding Window
group:
  - Arrays
isProblem: true
stars: 4
---
#dsa
[[_010 Computer Science MOC]]
[[DSA Map.canvas|DSA Learning Map]]
[[PG_ DSA|DSA MOC]]
[[PG_Sliding_Window_Problems]]]

# Best Time to Buy and Sell Stock 
## Description 
You are given an integer array `prices` where `prices[i]` is the price of NeetCoin on the `ith` day.

You may choose a **single day** to buy one NeetCoin and choose a **different day in the future** to sell it.

Return the maximum profit you can achieve. You may choose to **not make any transactions**, in which case the profit would be `0`.

**Example 1:**

```java
Input: prices = [10,1,5,6,7,1]

Output: 6
```

Explanation: Buy `prices[1]` and sell `prices[4]`, `profit = 7 - 1 = 6`.

**Example 2:**

```java
Input: prices = [10,8,7,5,2]

Output: 0
```

Explanation: No profitable transactions can be made, thus the max profit is 0.

**Constraints:**

- `1 <= prices.length <= 100`
- `0 <= prices[i] <= 100`
## Code 
```cpp
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2){
            return 0; 
        }
        int res = 0; 
        int curr_min = 1e5; 
        for (int i=0; i < prices.size(); ++i){
            curr_min = std::min(curr_min, prices[i]);
            res = std::max(prices[i]-curr_min, res); 
        }
        return res;

        
    }
};
```
