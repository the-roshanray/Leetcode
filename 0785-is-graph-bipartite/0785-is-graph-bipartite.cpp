class Solution {
public:
    bool dfs(int node, int col, vector<vector<int>>& graph,
             vector<int>& color) {
        color[node] = col;

        for (auto neigh : graph[node]) {
            if (color[neigh] == -1) {
                if (!dfs(neigh, 1 - col, graph, color))
                    return false;
            } else if (color[neigh] == color[node]) {
                return false;
            }
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);

        for (int i = 0; i < n; i++) {
            if (color[i] == -1) {
                if (!dfs(i, 0, graph, color))
                    return false;
            }
        }

        return true;
    }
};