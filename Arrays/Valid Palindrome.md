---
status: Done
difficulty: Easy
algo: Two-Pointers
group:
  - Arrays
isProblem: true
stars: 4
---
#dsa
[[_010 Computer Science MOC]]
[[DSA Map.canvas|DSA Learning Map]]
[[PG_ DSA|DSA MOC]]
[[PG_Two-Pointers_Problems]]

# Valid Palindrome
## Description 
Given a string `s`, return `true` if it is a **palindrome**, otherwise return `false`.

A **palindrome** is a string that reads the same forward and backward. It is also case-insensitive and ignores all non-alphanumeric characters.

**Note:** Alphanumeric characters consist of letters `(A-Z, a-z)` and numbers `(0-9)`.

**Example 1:**

```java
Input: s = "Was it a car or a cat I saw?"

Output: true
```

Explanation: After considering only alphanumerical characters we have "wasitacaroracatisaw", which is a palindrome.

**Example 2:**

```java
Input: s = "tab a cat"

Output: false
```

Explanation: "tabacat" is not a palindrome.

**Constraints:**

- `1 <= s.length <= 1000`
- `s` is made up of only printable ASCII characters.
## Code 
```cpp
class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0; 
        int right = s.length() - 1; 

        while (left < right) {
            while (left < right && !std::isalnum(s[left])){
                left++; 
            }
            while (left < right && !std::isalnum(s[right])){
                right--; 
            }
            if (std::tolower(s[left]) != std::tolower(s[right])){
                return false; 
            }

            left++; 
            right--; 
        }
        return true; 
    }
};
```
