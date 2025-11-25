---
status: Done
difficulty: Easy
algo: Stacks
group:
  - Stacks & Queues
isProblem: true
stars: 2
---
#dsa
[[_010 Computer Science MOC]]
[[DSA Map.canvas|DSA Learning Map]]
[[PG_ DSA|DSA MOC]]
[[PG_Stacks_Problems]]

# Baseball Game
## Description 
You are keeping the scores for a baseball game with strange rules. At the beginning of the game, you start with an empty record.

Given a list of strings `operations`, where `operations[i]` is the `ith` operation you must apply to the record and is one of the following:

- An integer `x`: Record a new score of `x`.
    
- '+': Record a new score that is the sum of the previous two scores.
    
- 'D': Record a new score that is the double of the previous score.
    
- 'C': Invalidate the previous score, removing it from the record.
    

Return the sum of all the scores on the record after applying all the operations.

Note: The test cases are generated such that the answer and all intermediate calculations fit in a `32`-bit integer and that all operations are valid.

**Example 1:**

```java
Input: ops = ["1","2","+","C","5","D"]

Output: 18
```

Explanation:

- `"1"` - Add 1 to the record, record = [1].
- `"2"` - Add 2 to the record, record = [1, 2].
- `"+"` - Add `1 + 2 = 3` to the record, record = [1, 2, 3].
- `"C"` - Invalidate and remove the previous score, record = [1, 2].
- `"5"` - Add 5 to the record, record = [1, 2, 5].
- `"D"` - Add `2 * 5 = 10` to the record, record = [1, 2, 5, 10].
- The total sum is `1 + 2 + 5 + 10 = 18`.

**Example 2:**

```java
Input: ops = ["5","D","+","C"]

Output: 15
```

Explanation:

- `"5"` - Add 5 to the record, record = [5].
- `"D"` - Add `2 * 5 = 10` to the record, record = [5, 10].
- `"+"` - Add `5 + 10 = 15` to the record, record = [5, 10, 15].
- `"C"` - Invalidate and remove the previous score, record = [5, 10].
- The total sum is `5 + 10 = 15`.

**Constraints:**

- `1 <= operations.length <= 1000`
- `operations[i]` is `"C"`, `"D"`, `+`, or a string representing an integer in the range `[(-30,000), (30,000)]`.
- For operation `"+"`, there will always be at least two previous scores on the record.
- For operations `"C"` and `"D"`, there will always be at least one previous score on the record.

## Code 
```cpp
class Solution {
public:
    int calPoints(vector<string>& operations) {
        std::stack<int> stack; 
        int res = 0; 

        for (const auto& str: operations) {
            std::cout << res << '\n';
            if (str == "+") {
                int top = stack.top(); 
                stack.pop(); 
                int second = stack.top(); 
                stack.pop(); 
                int sum = top + second; 
                res += sum; 
                stack.push(second); 
                stack.push(top); 
                stack.push(sum); 
            } else if (str == "C") {
                int top = stack.top(); 
                stack.pop(); 
                res -= top; 
            } else if (str == "D") {
                int top = stack.top(); 
                int d = top * 2;
                stack.push(d); 
                res += d;  
            } else {
                int val = std::stoi(str); 
                res += val; 
                stack.push(val); 
            }
        }
        return res; 
    }
};
```