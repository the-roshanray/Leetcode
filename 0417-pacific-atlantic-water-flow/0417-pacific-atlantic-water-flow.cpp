class Solution {
public:
    void bfs(queue<pair<int, int>>& q, vector<vector<bool>>& vis,
             vector<vector<int>>& heights, int m, int n) {

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nr = r + dr[k];
                int nc = c + dc[k];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n && !vis[nr][nc] &&
                    heights[nr][nc] >= heights[r][c]) {

                    vis[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> pac(m, vector<bool>(n, false));
        vector<vector<bool>> atl(m, vector<bool>(n, false));

        queue<pair<int, int>> pacQ, atlQ;

        // Pacific border
        for (int i = 0; i < m; i++) {
            pac[i][0] = true;
            pacQ.push({i, 0});
        }

        for (int j = 0; j < n; j++) {
            pac[0][j] = true;
            pacQ.push({0, j});
        }

        // Atlantic border
        for (int i = 0; i < m; i++) {
            atl[i][n - 1] = true;
            atlQ.push({i, n - 1});
        }

        for (int j = 0; j < n; j++) {
            atl[m - 1][j] = true;
            atlQ.push({m - 1, j});
        }

        bfs(pacQ, pac, heights, m, n);
        bfs(atlQ, atl, heights, m, n);

        vector<vector<int>> ans;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pac[i][j] && atl[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};