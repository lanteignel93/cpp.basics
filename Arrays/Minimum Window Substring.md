---
status: Done
difficulty: Hard
algo: Sliding Window
group:
  - Arrays
isProblem: true
stars: 3
---
#dsa
[[_010 Computer Science MOC]]
[[DSA Map.canvas|DSA Learning Map]]
[[PG_ DSA|DSA MOC]]
[[PG_Sliding_Window_Problems]]

# Minimum Window Substring 
## Description 
Given two strings `s` and `t`, return the shortest **substring** of `s` such that every character in `t`, including duplicates, is present in the substring. If such a substring does not exist, return an empty string `""`.

You may assume that the correct output is always unique.

**Example 1:**

```java
Input: s = "OUZODYXAZV", t = "XYZ"

Output: "YXAZ"
```

Explanation: `"YXAZ"` is the shortest substring that includes `"X"`, `"Y"`, and `"Z"` from string `t`.

**Example 2:**

```java
Input: s = "xyz", t = "xyz"

Output: "xyz"
```

**Example 3:**

```java
Input: s = "x", t = "xy"

Output: ""
```

**Constraints:**

- `1 <= s.length <= 1000`
- `1 <= t.length <= 1000`
- `s` and `t` consist of uppercase and lowercase English letters.
## Code 
```cpp
class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        if (t.empty()) return ""; 

        std::unordered_map<char, int> countT, window; 

        for (char c : t) {
            countT[c]++; 
        }

        int have = 0, need = static_cast<int>(countT.size()); 
        std::pair<int, int> res = {-1, -1}; 
        int resLen = INT_MAX;
        int l = 0; 

        for (int r = 0; r < s.length(); r++) {
            char c = s[r]; 
            window[c]++; 

            if (countT.count(c) && window[c] == countT[c]) {
                have++; 
            }

            while (have == need) {
                if ((r-l + 1) < resLen) {
                    resLen = r - l + 1; 
                    res = {l, r};
                }

                window[s[l]]--; 
                if (countT.count(s[l]) && window[s[l]] < countT[s[l]]) {
                    have--;
                }
                l++;
            }
        }

        return resLen == INT_MAX ? "" : s.substr(res.first, resLen); 
    }
};
```
