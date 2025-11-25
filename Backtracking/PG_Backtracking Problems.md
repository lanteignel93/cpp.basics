---
status: TBD
difficulty: Medium
algo: Backtracking
group:
  - Backtracking
isProblem: false
---
#dsa
[[_010 Computer Science MOC]]
[[DSA Map.canvas|DSA Learning Map]]
[[PG_ DSA|DSA MOC]]
# Theory 
https://neetcode.io/courses/dsa-for-beginners/22
# Key Problems 
 ```dataview
TABLE WITHOUT ID file.link as Problem,difficulty, status, stars, algo
FROM "Programming/DSA Learning"
WHERE isProblem AND algo = "Backtracking" AND stars >= 4
SORT stars desc, difficulty desc
```
# Practice
 ```dataview
TABLE WITHOUT ID file.link as Problem, difficulty, status, stars, algo
FROM "Programming/DSA Learning"
WHERE isProblem AND algo = "Backtracking" AND stars < 4
SORT stars desc, difficulty desc
```
