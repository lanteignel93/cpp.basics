---
status: TBD
difficulty: Medium
algo: Bucket Sort
group:
  - Sorting
isProblem: false
---
#dsa
[[_010 Computer Science MOC]]
[[DSA Map.canvas|DSA Learning Map]]
[[PG_ DSA|DSA MOC]]
# Theory 
https://neetcode.io/courses/dsa-for-beginners/13

```cpp
void bucketSort(std::vector<int> &arr){	
    // Assume we have values between 0, 1, 2 
    int counts[] = {0, 0, 0}; 

    for (int num : arr) {
        counts[num]++; 
    }

    int i = 0; 
    for (int n = 0; n < 3; n++) {
        for (int j = 0; j < counts[n]; j++) {
            arr[i++] = n; 
        }
    }
}
```
# Key Problems 
 ```dataview
TABLE WITHOUT ID file.link as Problem,difficulty, status, stars, algo
FROM "Programming/DSA Learning"
WHERE isProblem AND algo = "Bucket Sort" AND stars >= 4
SORT stars desc, difficulty desc
```

# Practice
 ```dataview
TABLE WITHOUT ID file.link as Problem, difficulty, status, stars, algo
FROM "Programming/DSA Learning"
WHERE isProblem AND algo = "Bucket Sort" AND stars < 4
SORT stars desc, difficulty desc
```