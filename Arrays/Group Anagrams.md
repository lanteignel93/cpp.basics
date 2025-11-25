---
status: Done
difficulty: Medium
algo: hash
group:
  - Arrays
isProblem: true
stars: 4
---
#dsa
[[_010 Computer Science MOC]]
[[DSA Map.canvas|DSA Learning Map]]
[[PG_ DSA|DSA MOC]]
[[PG_Arrays_&_Hashing_Starter_Problems]]

# Group Anagrams
## Description 

Given an array of strings `strs`, group the

together. You can return the answer in **any order**.

**Example 1:**

**Input:** `strs = ["eat","tea","tan","ate","nat","bat"]`

**Output:**` [["bat"],["nat","tan"],["ate","eat","tea"]]`

**Explanation:**

- There is no string in strs that can be rearranged to form `"bat"`.
- The strings `"nat"` and `"tan"` are anagrams as they can be rearranged to form each other.
- The strings `"ate"`, `"eat"`, and `"tea"` are anagrams as they can be rearranged to form each other.

**Example 2:**

**Input:** `strs = [""]`

**Output:** `[[""]]`

**Example 3:**

**Input:** `strs = ["a"]`

**Output:** `[["a"]]`

**Constraints:**

- `1 <= strs.length <= 104`
- `0 <= strs[i].length <= 100`
- `strs[i]` consists of lowercase English letters.

## Code 
```cpp
class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    std::unordered_map<std::string, std::vector<std::string>> map;

    for (std::string str : strs) {
      std::string og = str;
      std::sort(str.begin(), str.end());
      map[str].push_back(og);
    }

    std::vector<std::vector<std::string>> res;
    for (const auto &pair : map) {
      res.push_back(pair.second);
    }
    return res;
  }
};
```
