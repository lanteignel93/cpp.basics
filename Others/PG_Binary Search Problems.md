---
status: TBD
difficulty: Easy
algo: Binary Search
group:
  - Others
isProblem: false
---
#dsa
[[_010 Computer Science MOC]]
[[DSA Map.canvas|DSA Learning Map]]
[[PG_ DSA|DSA MOC]]

# Theory 
https://neetcode.io/courses/dsa-for-beginners/16

```cpp
class TreeNode {
	private:
		int val_; 
		TreeNode *left = nullptr; 
		TreeNode *right = nullptr; 
		
	public:
		TreeNode(int val, TreeNode *l, TreeNode *r)
			: val_(val), left(l), right(r) {}
		TreeNode(int val)
			: TreeNode(val, nullptr, nullptr) {}
}; 
```
# Key Problems 
 ```dataview
TABLE WITHOUT ID file.link as Problem,difficulty, status, stars, algo
FROM "Programming/DSA Learning"
WHERE isProblem AND algo = "Binary Search" AND stars >= 4
SORT stars desc, difficulty desc
```
# Practice
 ```dataview
TABLE WITHOUT ID file.link as Problem, difficulty, status, stars, algo
FROM "Programming/DSA Learning"
WHERE isProblem AND algo = "Binary Search" AND stars < 4
SORT stars desc, difficulty desc
```