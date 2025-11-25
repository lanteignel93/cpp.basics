---
status: Done
difficulty: Medium
algo: Stacks
group:
  - Stacks & Queues
isProblem: true
stars: 3
---
#dsa
[[_010 Computer Science MOC]]
[[DSA Map.canvas|DSA Learning Map]]
[[PG_ DSA|DSA MOC]]
[[PG_Stacks_Problems]]

# Minimum Stack
## Description 
You are given an array of strings `tokens` that represents a **valid** arithmetic expression in [Reverse Polish Notation](https://en.wikipedia.org/wiki/Reverse_Polish_notation).

Return the integer that represents the evaluation of the expression.

- The operands may be integers or the results of other operations.
- The operators include `'+'`, `'-'`, `'*'`, and `'/'`.
- Assume that division between integers always truncates toward zero.

**Example 1:**

```java
Input: tokens = ["1","2","+","3","*","4","-"]

Output: 5

Explanation: ((1 + 2) * 3) - 4 = 5
```

**Constraints:**

- `1 <= tokens.length <= 1000`.
- tokens[i] is `"+"`, `"-"`, `"*"`, or `"/"`, or a string representing an integer in the range `[-100, 100]`.
## Code 
```cpp
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> _stack; 

        for (const auto& tok : tokens) {
            if (tok == "+") {
                int v1 = _stack.top(); 
                _stack.pop(); 
                int v2 = _stack.top(); 
                _stack.pop(); 
                _stack.push(v1 + v2); 

            } else if (tok == "-") {
                int v1 = _stack.top(); 
                _stack.pop(); 
                int v2 = _stack.top();
                _stack.pop(); 
                _stack.push(v2 - v1);  
            } else if (tok == "*") {
                int v1 = _stack.top(); 
                _stack.pop(); 
                int v2 = _stack.top();
                _stack.pop(); 
                _stack.push(v1 * v2);  
                
            } else if (tok == "/") {
                int v1 = _stack.top(); 
                _stack.pop(); 
                int v2 = _stack.top();
                _stack.pop(); 
                _stack.push(v2 / v1);  

            } else {
                _stack.push(std::stoi(tok)); 
            }
        }

        return _stack.top(); 
    }
};

```