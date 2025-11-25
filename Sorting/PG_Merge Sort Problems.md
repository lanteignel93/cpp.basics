---
status: TBD
difficulty: Medium
algo: Merge Sort
group:
  - Sorting
isProblem: false
---
#dsa
[[_010 Computer Science MOC]]
[[DSA Map.canvas|DSA Learning Map]]
[[PG_ DSA|DSA MOC]]
# Theory 
https://neetcode.io/courses/dsa-for-beginners/11
```cpp 
#include <vector> 

void merge(std::vector<int> &arr, int s, int m, int e) {
    std::vector<int> L = {arr.begin() + s, arr.begin() + m + 1}; 
    std::vector<int> R = {arr.begin() + m + 1, arr.begin() + e + 1};

    int i = 0, j = 0, k = s; 

    while (i < L.size() && j < R.size()) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++]; 
        }
    } 

    while (i < L.size()) {
        arr[k++] = L[i++]; 
    }
    while (j < R.size()) {
        arr[k++] = R[j++];
    }
}


void mergeSort(std::vector<int> &arr, int s, int e) {
    if (s >= e) {
        return ; 
    }

    int m = s + (e - s) / 2;

    mergeSort(arr, s, m); 
    mergeSort(arr, m+1, e);
    merge(arr, s, e); 
}
```
# Key Problems 
 ```dataview
TABLE WITHOUT ID file.link as Problem,difficulty, status, stars, algo
FROM "Programming/DSA Learning"
WHERE isProblem AND algo = "Merge Sort" AND stars >= 4
SORT stars desc, difficulty desc
```

# Practice
 ```dataview
TABLE WITHOUT ID file.link as Problem, difficulty, status, stars, algo
FROM "Programming/DSA Learning"
WHERE isProblem AND algo = "Merge Sort" AND stars < 4
SORT stars desc, difficulty desc
```