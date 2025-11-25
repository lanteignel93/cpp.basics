---
status: Done
difficulty: Easy
algo: Two-Pointers
group:
  - Arrays
isProblem: true
stars: 1
---
#dsa
[[_010 Computer Science MOC]]
[[DSA Map.canvas|DSA Learning Map]]
[[PG_ DSA|DSA MOC]]
[[PG_Two-Pointers_Problems]]

# Reverse String
## Description 
You are given an array of characters which represents a string `s`. Write a function which reverses a string.

You must do this by modifying the input array in-place with `O(1)` extra memory.

**Example 1:**

```java
Input: s = ["n","e","e","t"]

Output: ["t","e","e","n"]
```

**Example 2:**

```java
Input: s = ["r","a","c","e","c","a","r"]

Output: ["r","a","c","e","c","a","r"]
```

**Constraints:**

- `0 <= s.length < 100,000`
- `s[i]` is a [printable ascii character](https://en.wikipedia.org/wiki/ASCII#Printable_characters).
## Code 
```cpp
class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = static_cast<int>(s.size()); 
        for (int i = 0; i < n / 2; ++i){
            int j = n - i - 1; 
            std::swap(s[i], s[j]); 
        }
    }
};
```
