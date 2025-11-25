---
status: Done
difficulty: Medium
algo: Backtracking
group:
  - Stacks & Queues
  - Backtracking
isProblem: true
stars: 4
---
#dsa
[[_010 Computer Science MOC]]
[[DSA Map.canvas|DSA Learning Map]]
[[PG_ DSA|DSA MOC]]
[[PG_Stacks_Problems]]

# Generate Parentheses
## Description 
You are given an integer `n`. Return all well-formed parentheses strings that you can generate with `n` pairs of parentheses.

**Example 1:**

```java
Input: n = 1

Output: ["()"]
```

**Example 2:**

```java
Input: n = 3

Output: ["((()))","(()())","(())()","()(())","()()()"]
```

You may return the answer in **any order**.

**Constraints:**

- `1 <= n <= 7`
## Code 
```cpp
class Solution {
public:
    std::stack<std::string> _stack; 
    std::vector<std::string> res;  

    vector<string> generateParenthesis(int n) {
        backtracking(0, 0, n); 
        return res;
    }

    void backtracking(int open, int close, int n) {
        if (open == close && open == n) {
            std::stack<std::string> tmp_stack = _stack;  
            std::string resStr = ""; 
            while (!tmp_stack.empty()) {
                resStr += tmp_stack.top(); 
                tmp_stack.pop(); 
            }
            std::reverse(resStr.begin(), resStr.end());
            res.push_back(resStr); 
        } else if (open < n) {
            _stack.push("("); 
            backtracking(open + 1, close, n); 
            _stack.pop(); 
        }

        if (close < open) {
            _stack.push(")"); 
            backtracking(open, close + 1, n); 
            _stack.pop(); 
        }
    }
};

```