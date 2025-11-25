---
status: Done
difficulty: Medium
algo: Stacks
group:
  - Stacks & Queues
isProblem: true
stars: 5
---
#dsa
[[_010 Computer Science MOC]]
[[DSA Map.canvas|DSA Learning Map]]
[[PG_ DSA|DSA MOC]]
[[PG_Stacks_Problems]]

# Decode String
## Description 
You are given an encoded string `s`, return its decoded string.

The encoding rule is: `k[encoded_string]`, where the encoded_string inside the square brackets is being repeated exactly `k` times. Note that `k` is guaranteed to be a **positive integer**.

You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. There will not be input like `3a`, `2[4]`, `a[a]` or `a[2]`.

The test cases are generated so that the length of the output will never exceed `100,000`.

**Example 1:**

```java
Input: s = "2[a3[b]]c"

Output: "abbbabbbc"
```

**Example 2:**

```java
Input: s = "axb3[z]4[c]"

Output: "axbzzzcccc"
```

**Example 3:**

```java
Input: s = "ab2[c]3[d]1[x]"

Output: "abccdddx"
```

**Constraints:**

- `1 <= s.length <= 30`
- `s` is made up of lowercase English letters, digits, and square brackets `'[]'`.
- All the integers in `s` are in the range `[1, 300]`.
- `s` is guaranteed to be a valid input.
## Code 
```cpp
class Solution {
  public:
    std::string decodeString(std::string s) {
        std::stack<std::string> _stack;

        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];
            if (std::isdigit(c)) {
                std::string num_str = "";
                while (i < s.length() && std::isdigit(s[i])) {
                    num_str += s[i];
                    i++;
                }
                _stack.push(num_str);
                i--;
            } else if (c == '[') {
                _stack.push("[");
            } else if (c == ']') {
                std::string decoded_segment = "";
                while (!_stack.empty() && _stack.top() != "[") {
                    decoded_segment = _stack.top() + decoded_segment;
                    _stack.pop();
                }
                if (!_stack.empty()) {
                    _stack.pop();
                }
                int multiplier = 1;
                if (!_stack.empty()) {
                    multiplier = std::stoi(_stack.top());
                    _stack.pop();
                }

                std::string repeated_string = "";
                for (int k = 0; k < multiplier; k++) {
                    repeated_string += decoded_segment;
                }
                _stack.push(repeated_string);

            } else {
                _stack.push(std::string(1, c));
            }
        }

        std::string res = "";
        while (!_stack.empty()) {
            res = _stack.top() + res;
            _stack.pop();
        }

        return res;
    }
};

```