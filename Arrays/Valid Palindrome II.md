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

# Valid Palindrome II
## Description 
You are given a string `s`, return true if the `s` can be a palindrome after deleting at most one character from it.

A **palindrome** is a string that reads the same forward and backward.

**Note:** Alphanumeric characters consist of letters `(A-Z, a-z)` and numbers `(0-9)`.

**Example 1:**

```java
Input: s = "aca"

Output: true
```

Explanation: "aca" is already a palindrome.

**Example 2:**

```java
Input: s = "abbadc"

Output: false
```

Explanation: "abbadc" is not a palindrome and can't be made a palindrome after deleting at most one character.

**Example 3:**

```java
Input: s = "abbda"

Output: true
```

Explanation: "We can delete the character 'd'.

**Constraints:**

- `1 <= s.length <= 100,000`
- `s` is made up of only lowercase English letters.
## Code 
```cpp
class Solution {
private: 
    bool isSubPalindrome(const std::string& s, int left, int right){
        while (left < right) {
            if (s[left] != s[right])
                return false; 
            left++; 
            right--; 
        }
        return true;
    }

public:
    bool validPalindrome(string s) {
        int left = 0, right = static_cast<int>(s.size()) -1;

        while(left < right){
            if (s[left] != s[right]){
                return isSubPalindrome(s, left + 1, right) || isSubPalindrome(s, left, right - 1); 
            }
            left++; 
            right--;
        }
        return true;
    }
};
```
