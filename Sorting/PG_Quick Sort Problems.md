---
status: TBD
difficulty: Medium
algo: Quick Sort
group:
  - Sorting
isProblem: false
---
#dsa
[[_010 Computer Science MOC]]
[[DSA Map.canvas|DSA Learning Map]]
[[PG_ DSA|DSA MOC]]
# Theory 
https://neetcode.io/courses/dsa-for-beginners/12

```cpp
#include <vector> 

void quickSort(std::vector<int> &arr, int s, int e) {
    if (s >= e) {
        return; 
    }

    int pivot = arr[e]; 
    int left = s; 

    for (int i = s; i < e; i++) {
        if (arr[i] < pivot) {
            int tmp = arr[left]; 
            arr[left] = arr[i]; 
            arr[i] = tmp; 
            ++left; 
        }
    }

    arr[e] = arr[left]; 
    arr[left] = arr[pivot];
    
    quickSort(arr, s, left - 1); 
    quickSort(arr, left + 1, e); 
}
```
# Key Problems 
 ```dataview
TABLE WITHOUT ID file.link as Problem,difficulty, status, stars, algo
FROM "Programming/DSA Learning"
WHERE isProblem AND algo = "Quick Sort" AND stars >= 4
SORT stars desc, difficulty desc
```
# Practice
 ```dataview
TABLE WITHOUT ID file.link as Problem, difficulty, status, stars, algo
FROM "Programming/DSA Learning"
WHERE isProblem AND algo = "Quick Sort" AND stars < 4
SORT stars desc, difficulty desc
```