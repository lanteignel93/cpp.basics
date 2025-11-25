---
status: Done
difficulty: Easy
algo: BFS
group:
  - Trees
isProblem: true
stars: 4
---
#dsa
[[_010 Computer Science MOC]]
[[DSA Map.canvas|DSA Learning Map]]
[[PG_ DSA|DSA MOC]]
[[PG_Breath First Search Problems]]

# Average of Levels in Binary Tree
## Description 
There is a **bi-directional** graph with `n` vertices, where each vertex is labeled from `0` to `n - 1` (**inclusive**). The edges in the graph are represented as a 2D integer array `edges`, where each `edges[i] = [ui, vi]` denotes a bi-directional edge between vertex `ui` and vertex `vi`. Every vertex pair is connected by **at most one** edge, and no vertex has an edge to itself.

You want to determine if there is a **valid path** that exists from vertex `source` to vertex `destination`.

Given `edges` and the integers `n`, `source`, and `destination`, return `true` _if there is a **valid path** from_ `source` _to_ `destination`_, or_ `false` _otherwise__._

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/08/14/validpath-ex1.png)
```
**Input:** n = 3, edges = [[0,1],[1,2],[2,0]], source = 0, destination = 2
**Output:** true
**Explanation:** There are two paths from vertex 0 to vertex 2:
- 0 → 1 → 2
- 0 → 2
```

**Example 2:**

![](https://assets.leetcode.com/uploads/2021/08/14/validpath-ex2.png)

```
**Input:** n = 6, edges = [[0,1],[0,2],[3,5],[5,4],[4,3]], source = 0, destination = 5
**Output:** false
**Explanation:** There is no path from vertex 0 to vertex 5.
```

**Constraints:**

- `1 <= n <= 2 * 105`
- `0 <= edges.length <= 2 * 105`
- `edges[i].length == 2`
- `0 <= ui, vi <= n - 1`
- `ui != vi`
- `0 <= source, destination <= n - 1`
- There are no duplicate edges.
- There are no self edges.


## Code 
```cpp
class Solution {
  public:
    bool validPath(int n, vector<vector<int>> &edges, int source,
                   int destination) {
        std::unordered_map<int, std::vector<int>> graph;

        for (auto e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        std::vector<bool> visited(n, 0);
        std::queue<int> q;
        q.push(source);
        visited[source] = 1;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            if (curr == destination) {
                return true;
            }
            for (const auto &node : graph[curr]) {
                if (!visited[node]) {
                    q.push(node);
                    visited[node] = 1;
                }
            }
        }
        return false;
    }
};

```