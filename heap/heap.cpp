/*
You are given an 2-D array points where points[i] = [xi, yi] represents the
coordinates of a point on an X-Y axis plane. You are also given an integer k.

Return the k closest points to the origin (0, 0).

The distance between two points is defined as the Euclidean distance (sqrt((x1 -
x2)^2 + (y1 - y2)^2)).

You may return the answer in any order.
*/
class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
        auto comp = [](const std::vector<int> &a, const std::vector<int> b) {
            return a[0] * a[0] + a[1] * a[1] > b[0] * b[0] + b[1] * b[1];
        };

        std::priority_queue<std::vector<int>, std::vector<std::vector<int>>,
                            decltype(comp)>
            minHeap(comp);

        for (const auto &point : points) {
            minHeap.push(point);
        }

        std::vector<std::vector<int>> res;
        for (int i = 0; i < k; ++i) {
            res.push_back(minHeap.top());
            minHeap.pop();
        }
        return res;
    }
};
