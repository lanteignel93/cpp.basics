---
status: TBD
difficulty: Medium
algo: Combinations
group:
  - Backtracking
isProblem: false
---
#dsa
[[_010 Computer Science MOC]]
[[DSA Map.canvas|DSA Learning Map]]
[[PG_ DSA|DSA MOC]]
# Theory 
https://neetcode.io/courses/advanced-algorithms/12
# Key Problems 
 ```dataview
TABLE WITHOUT ID file.link as Problem,difficulty, status, stars, algo
FROM "Programming/DSA Learning"
WHERE isProblem AND algo = "Combinations" AND stars >= 4
SORT stars desc, difficulty desc
```
# Practice
 ```dataview
TABLE WITHOUT ID file.link as Problem, difficulty, status, stars, algo
FROM "Programming/DSA Learning"
WHERE isProblem AND algo = "Combinations" AND stars < 4
SORT stars desc, difficulty desc
```
