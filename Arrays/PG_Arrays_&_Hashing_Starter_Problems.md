---
status: TBD
difficulty: Easy
algo:
group:
  - Arrays
isProblem: false
---
#dsa
[[_010 Computer Science MOC]]
[[DSA Map.canvas|DSA Learning Map]]
[[PG_ DSA|DSA MOC]]
# Theory 

# Key Problems 
 ```dataview
TABLE WITHOUT ID file.link as Problem,difficulty, status, stars, algo
FROM "Programming/DSA Learning"
WHERE isProblem AND (algo = "array" OR algo = "hash") AND stars >= 4
SORT stars desc
```

# Practice
 ```dataview
TABLE WITHOUT ID file.link as Problem,difficulty, status, stars, algo
FROM "Programming/DSA Learning"
WHERE isProblem AND (algo = "array" OR algo = "hash") AND stars < 4
SORT stars desc
```
