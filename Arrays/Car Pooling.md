---
status: Done
difficulty: Medium
algo: Prefix Sums
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

# Car Pooling
## Description 
There is a car with `capacity` empty seats. The vehicle only drives east (i.e., it cannot turn around and drive west).

You are given the integer `capacity` and an array `trips` where `trips[i] = [numPassengersi, fromi, toi]` indicates that the `ith` trip has `numPassengersi` passengers and the locations to pick them up and drop them off are `fromi` and `toi` respectively. The locations are given as the number of kilometers due east from the car's initial location.

Return `true` _if it is possible to pick up and drop off all passengers for all the given trips, or_ `false` _otherwise_.

**Example 1:**
```
**Input:** trips = [[2,1,5],[3,3,7]], capacity = 4
**Output:** false
```
**Example 2:**

```
**Input:** trips = [[2,1,5],[3,3,7]], capacity = 5
**Output:** true
```
**Constraints:**

- `1 <= trips.length <= 1000`
- `trips[i].length == 3`
- `1 <= numPassengersi <= 100`
- `0 <= fromi < toi <= 1000`
- `1 <= capacity <= 105`
## Code 
```cpp
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        std::vector<int> time(1001,0); 

        for (const auto& trip : trips) {
            int num_pass = trip[0]; 
            int pickup_loc = trip[1]; 
            int dropoff_loc = trip[2]; 

            time[pickup_loc] += num_pass; 
            time[dropoff_loc] -= num_pass;
        }

        int curr_pass = 0; 

        for (int i = 0; i < 1001; i++) {
            curr_pass += time[i]; 
            if (curr_pass > capacity) return false; 
        }
        return true;
    }
};
```

