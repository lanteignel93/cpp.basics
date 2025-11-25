---
status: TBD
difficulty: Medium
algo: Fast and Slow Pointer
group:
  - Linked List
isProblem: false
---
#dsa
[[_010 Computer Science MOC]]
[[DSA Map.canvas|DSA Learning Map]]
[[PG_ DSA|DSA MOC]]
# Key Problems 
 ```dataview
TABLE WITHOUT ID file.link as Problem,difficulty, status, stars, algo
FROM "Programming/DSA Learning"
WHERE isProblem AND algo = "Fast and Slow Pointer" AND stars >= 4
SORT stars desc, difficulty desc
```
# Practice
 ```dataview
TABLE WITHOUT ID file.link as Problem, difficulty, status, stars, algo
FROM "Programming/DSA Learning"
WHERE isProblem AND algo = "Fast and Slow Pointer" AND stars < 4
SORT stars desc, difficulty desc
```
