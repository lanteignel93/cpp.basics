---
status: Done
difficulty: Medium
algo: DFS - Recursive
group:
  - Trees
isProblem: true
stars: 2
---
#dsa
[[_010 Computer Science MOC]]
[[DSA Map.canvas|DSA Learning Map]]
[[PG_ DSA|DSA MOC]]
[[PG_Depth First Search (DFS) - Recursive Problems]]

# Course Schedule
## Description 
There are a total of `numCourses` courses you have to take, labeled from `0` to `numCourses - 1`. You are given an array `prerequisites` where `prerequisites[i] = [ai, bi]` indicates that you **must** take course `bi` first if you want to take course `ai`.

- For example, the pair `[0, 1]`, indicates that to take course `0` you have to first take course `1`.

Return `true` if you can finish all courses. Otherwise, return `false`.

**Example 1:**

**Input:** `numCourses = 2, prerequisites = [[1,0]]`
**Output:** true
**Explanation:** There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.

**Example 2:**

**Input:** `numCourses = 2, prerequisites = [[1,0],[0,1]]`
**Output:** false
**Explanation:** There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

**Constraints:**

- `1 <= numCourses <= 2000`
- `0 <= prerequisites.length <= 5000`
- `prerequisites[i].length == 2`
- `0 <= ai, bi < numCourses`
- `All the pairs prerequisites[i] are **unique**.`
## Code 
```cpp
class Solution {
  private:
    // States for cycle detection
    // 0: Unvisited
    // 1: Visiting (in current recursion path) -> Used to detect a cycle
    // 2: Visited (safe/processed) -> Used for memoization
    std::vector<int> state;

    // preReqMap: course -> list of prerequisites
    std::unordered_map<int, std::vector<int>> preReqMap;

    bool dfs(int course) {
        // 1. Cycle Detection (State 1: Visiting)
        if (state[course] == 1) {
            return false; // Found a cycle!
        }

        // 2. Memoization (State 2: Visited/Safe)
        if (state[course] == 2) {
            return true; // Already processed and found safe
        }

        // Mark current course as Visiting (State 1)
        state[course] = 1;

        // Process all prerequisites
        if (preReqMap.count(course)) {
            for (int prereq : preReqMap[course]) {
                if (!dfs(prereq)) {
                    return false; // Cycle detected deeper in the graph
                }
            }
        }

        // Mark current course as Visited/Safe (State 2) and return true
        state[course] = 2;
        return true;
    }

  public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {

        for (const auto &pre : prerequisites) {
            preReqMap[pre[0]].push_back(pre[1]);
        }

        // 2. Initialize the state array for all courses
        state.resize(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            if (!dfs(i)) {
                return false; // Found a cycle in this component
            }
        }

        return true; // No cycles found
    }
};
```