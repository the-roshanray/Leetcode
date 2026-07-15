class Solution {
public:
    void dfs(int node, vector<vector<int>>& isConnected, vector<bool>& vis) {
        vis[node] = true;

        for (int nei = 0; nei < isConnected.size(); nei++) {
            if (isConnected[node][nei] == 1 && !vis[nei]) {
                dfs(nei, isConnected, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> vis(n, false);
        int provinces = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                provinces++;
                dfs(i, isConnected, vis);
            }
        }

        return provinces;
    }
};