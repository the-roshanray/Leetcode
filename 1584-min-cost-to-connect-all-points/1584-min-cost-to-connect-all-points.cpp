class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        vector<bool> visited(n, false);

        pq.push({0, 0});

        int mstWeight = 0;
        int edgesUsed = 0;

        while (!pq.empty() && edgesUsed < n) {
            int weight = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (visited[node])
                continue;

            visited[node] = true;
            mstWeight += weight;
            edgesUsed++;

            for (int nextNode = 0; nextNode < n; nextNode++) {
                if (!visited[nextNode]) {
                    int edgeWeight =
                        abs(points[node][0] - points[nextNode][0]) +
                        abs(points[node][1] - points[nextNode][1]);

                    pq.push({edgeWeight, nextNode});
                }
            }
        }

        return mstWeight;
    }
};