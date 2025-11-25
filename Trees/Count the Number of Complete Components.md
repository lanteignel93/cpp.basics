---
status: Done
difficulty: Medium
algo: BFS
group:
  - Trees
isProblem: true
stars: 5
---
#dsa
[[_010 Computer Science MOC]]
[[DSA Map.canvas|DSA Learning Map]]
[[PG_ DSA|DSA MOC]]
[[PG_Breath First Search Problems]]

# Count the Number of Complete Components
## Description 
You are given an integer `n`. There is an **undirected** graph with `n` vertices, numbered from `0` to `n - 1`. You are given a 2D integer array `edges` where `edges[i] = [ai, bi]` denotes that there exists an **undirected** edge connecting vertices `ai` and `bi`.

Return _the number of **complete connected components** of the graph_.

A **connected component** is a subgraph of a graph in which there exists a path between any two vertices, and no vertex of the subgraph shares an edge with a vertex outside of the subgraph.

A connected component is said to be **complete** if there exists an edge between every pair of its vertices.

**Example 1:**

**![](https://assets.leetcode.com/uploads/2023/04/11/screenshot-from-2023-04-11-23-31-23.png)**

**Input:** `n = 6, edges = [[0,1],[0,2],[1,2],[3,4]]`
**Output:** `3`
**Explanation:** From the picture above, one can see that all of the components of this graph are complete.

**Example 2:**

**![](https://assets.leetcode.com/uploads/2023/04/11/screenshot-from-2023-04-11-23-32-00.png)**

**Input:** `n = 6, edges = [[0,1],[0,2],[1,2],[3,4],[3,5]]`
**Output:** `1`
**Explanation:** The component containing vertices 0, 1, and 2 is complete since there is an edge between every pair of two vertices. On the other hand, the component containing vertices 3, 4, and 5 is not complete since there is no edge between vertices 4 and 5. Thus, the number of complete components in this graph is 1.

**Constraints:**

- `1 <= n <= 50`
- `0 <= edges.length <= n * (n - 1) / 2`
- `edges[i].length == 2`
- `0 <= ai, bi <= n - 1`
- `ai != bi`
- There are no repeated edges.
## Code 
```cpp
class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        std::vector<std::vector<int>> graph(n);
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        std::vector<bool> visited(n, false);
        int completeComponents = 0;

        // Process each unvisited vertex
        for (int vertex = 0; vertex < n; vertex++) {
            if (!visited[vertex]) {
                // BFS to find all vertices in the current component
                std::vector<int> component;
                std::queue<int> q;
                q.push(vertex);
                visited[vertex] = true;

                while (!q.empty()) {
                    int current = q.front();
                    q.pop();
                    component.push_back(current);

                    // Process neighbors
                    for (int neighbor : graph[current]) {
                        if (!visited[neighbor]) {
                            q.push(neighbor);
                            visited[neighbor] = true;
                        }
                    }
                }

                // Check if component is complete (all vertices have the right
                // number of edges)
                bool isComplete = true;
                for (int node : component) {
                    if (graph[node].size() != component.size() - 1) {
                        isComplete = false;
                        break;
                    }
                }

                if (isComplete) {
                    completeComponents++;
                }
            }
        }

        return completeComponents;
    }
};
```