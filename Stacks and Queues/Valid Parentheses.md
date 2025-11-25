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

# Valid Parentheses 
## Description 
You are given a string `s` consisting of the following characters: `'('`, `')'`, `'{'`, `'}'`, `'['` and `']'`.

The input string `s` is valid if and only if:

1. Every open bracket is closed by the same type of close bracket.
2. Open brackets are closed in the correct order.
3. Every close bracket has a corresponding open bracket of the same type.

Return `true` if `s` is a valid string, and `false` otherwise.

**Example 1:**

```java
Input: s = "[]"

Output: true
```

**Example 2:**

```java
Input: s = "([{}])"

Output: true
```

**Example 3:**

```java
Input: s = "[(])"

Output: false
```

Explanation: The brackets are not closed in the correct order.

**Constraints:**

- `1 <= s.length <= 1000`

## Code 
```cpp
class Solution {

public:
    bool isValid(string s) {
        std::stack<char> stack;

        std::unordered_map<char, char> mapping = {
            {')', '('},
            {'}', '{'},
            {']', '['}

        };

        for (char c : s) {
            if (mapping.find(c) != mapping.end()) {
                char top_element = '!';

                if (!stack.empty()){
                    top_element = stack.top();
                    stack.pop();
                }
  
                if (mapping[c] != top_element) {
                    return false;
                }

            } else {
                stack.push(c);
            }
        }
        return stack.empty();
    }
};
```