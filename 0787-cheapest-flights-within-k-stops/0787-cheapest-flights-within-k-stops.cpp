class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
         vector<vector<pair<int, int>>> adj(n);
        for (auto &flight : flights)
        {
            int u = flight[0];
            int v = flight[1];
            int w = flight[2];

            adj[u].push_back({v, w});
        }

        vector<int> distance(n, INT_MAX);
        queue<pair<int, pair<int, int>>> q;

        q.push({0, {src, 0}});
        distance[src] = 0;

        while (!q.empty())
        {
            auto [stops, position] = q.front();
            q.pop();

            int node = position.first;
            int cost = position.second;

            if (stops > k)
                continue;

            for (auto &[adjNode, edgeWeight] : adj[node])
            {
                int newCost = cost + edgeWeight;

                if (newCost < distance[adjNode])
                {
                    distance[adjNode] = newCost;
                    q.push({stops + 1, {adjNode, newCost}});
                }
            }
        }
        return distance[dst] == INT_MAX ? -1 : distance[dst];
    }
};