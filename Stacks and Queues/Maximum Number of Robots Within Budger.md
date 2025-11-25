---
status: Done
difficulty: Hard
algo: Queues
group:
  - Stacks & Queues
isProblem: true
stars: 4
---
#dsa
[[_010 Computer Science MOC]]
[[DSA Map.canvas|DSA Learning Map]]
[[PG_ DSA|DSA MOC]]
[[PG_Queues_Problems]]

# Maximum Number of Robots Within Budger
## Description 
You have `n` robots. You are given two **0-indexed** integer arrays, `chargeTimes` and `runningCosts`, both of length `n`. The `ith` robot costs `chargeTimes[i]` units to charge and costs `runningCosts[i]` units to run. You are also given an integer `budget`.

The **total cost** of running `k` chosen robots is equal to `max(chargeTimes) + k * sum(runningCosts)`, where `max(chargeTimes)` is the largest charge cost among the `k` robots and `sum(runningCosts)` is the sum of running costs among the `k` robots.

Return _the **maximum** number of **consecutive** robots you can run such that the total cost **does not** exceed_ `budget`.

**Example 1:**
```
**Input:** chargeTimes = [3,6,1,3,4], runningCosts = [2,1,3,4,5], budget = 25
**Output:** 3
**Explanation:** 
It is possible to run all individual and consecutive pairs of robots within budget.
To obtain answer 3, consider the first 3 robots. The total cost will be max(3,6,1) + 3 * sum(2,1,3) = 6 + 3 * 6 = 24 which is less than 25.
It can be shown that it is not possible to run more than 3 consecutive robots within budget, so we return 3.
```

**Example 2:**

```
**Input:** chargeTimes = [11,12,19], runningCosts = [10,8,7], budget = 19
**Output:** 0
**Explanation:** No robot can be run that does not exceed the budget, so we return 0.
```

**Constraints:**

- `chargeTimes.length == runningCosts.length == n`
- `1 <= n <= 5 * 104`
- `1 <= chargeTimes[i], runningCosts[i] <= 105`
- `1 <= budget <= 1015`

## Code 
```cpp
class Solution {
  public:
    int maximumRobots(vector<int> &chargeTimes, vector<int> &runningCosts,
                      long long budget) {
        std::deque<int> maxQ;

        long long current_sum = 0;
        int left = 0;
        int max_length = 0;
        int n = static_cast<int>(chargeTimes.size());

        for (int right = 0; right < n; right++) {
            current_sum += runningCosts[right];

            // Maintain Monotonic Deque (Max ChargeTime)
            // Pop smaller elements from the back
            while (!maxQ.empty() &&
                   chargeTimes[maxQ.back()] <= chargeTimes[right]) {
                maxQ.pop_back();
            }
            maxQ.push_back(right);

            long long max_charge = chargeTimes[maxQ.front()];
            int window_size = right - left + 1;

            while (max_charge +
                       static_cast<long long>(window_size) * current_sum >
                   budget) {
                // If element leaving the window ('left') is the current max
                //  remove it from the deque's front
                if (maxQ.front() == left) {
                    maxQ.pop_front();
                }
                current_sum -= runningCosts[left];
                left++;

                max_charge = maxQ.empty() ? 0 : chargeTimes[maxQ.front()];
                window_size = right - left + 1;
            }

            max_length = std::max(max_length, right - left + 1);
        }
        return max_length;
    }
};
```
