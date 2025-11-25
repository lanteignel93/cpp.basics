---
status: Done
difficulty: Medium
algo: Stacks
group:
  - Stacks & Queues
isProblem: true
stars: 3
---
#dsa
[[_010 Computer Science MOC]]
[[DSA Map.canvas|DSA Learning Map]]
[[PG_ DSA|DSA MOC]]
[[PG_Stacks_Problems]]

# Asteroids Collision
## Description 
You are given an array `asteroids` of integers representing asteroids in a row. The indices of the asteroid in the array represent their relative position in space.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

**Example 1:**

```java
Input: asteroids = [2,4,-4,-1]

Output: [2]
```

**Example 2:**

```java
Input: asteroids = [5,5]

Output: [5,5]
```

**Example 3:**

```java
Input: asteroids = [7,-3,9]

Output: [7,9]
```

**Constraints:**

- `2 <= asteroids.length <= 10,000`.
- `-1000 <= asteroids[i] <= 1000`
- `asteroids[i] != 0`
## Code 
```cpp
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        std::stack<int> pos_stack; 
        std::stack<int> neg_stack; 
        std::vector<int> res; 

        for (int num : asteroids) {
            if (num < 0) {
                neg_stack.push(num); 
                while (!neg_stack.empty()){
                    if (!pos_stack.empty()){
                        int top_neg = neg_stack.top(); neg_stack.pop();
                        int top_pos = pos_stack.top(); pos_stack.pop(); 
    
                        if ((top_neg + top_pos) > 0) {
                            pos_stack.push(top_pos); 
                        } else if ((top_neg + top_pos) < 0) {
                            std::cout << top_neg + top_pos << '\n'; 
                            neg_stack.push(top_neg); 
                        }
                    } else {
                        res.push_back(neg_stack.top()); 
                        neg_stack.pop(); 
                    }
                }
            } else {
                pos_stack.push(num); 
            }
        } 


        std::vector<int> pos_vec; 
        while (!pos_stack.empty()) {
            pos_vec.push_back(pos_stack.top()); 
            pos_stack.pop(); 
        }
        std::reverse(pos_vec.begin(), pos_vec.end()); 
        
        for (int num : pos_vec) {
            res.push_back(num); 
        }
        return res; 
    }
};

```