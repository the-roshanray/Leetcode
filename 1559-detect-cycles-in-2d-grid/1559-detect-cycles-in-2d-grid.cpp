class Solution {
public:
    int m, n;
    vector<vector<bool>> visited;

    bool dfs(vector<vector<char>>& grid,
             int row, int col,
             int parentRow, int parentCol) {

        visited[row][col] = true;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int k = 0; k < 4; k++) {
            int nr = row + dr[k];
            int nc = col + dc[k];

            if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                continue;

            if (grid[nr][nc] != grid[row][col])
                continue;

            if (!visited[nr][nc]) {
                if (dfs(grid, nr, nc, row, col))
                    return true;
            }
            else if (nr != parentRow || nc != parentCol) {
                return true;
            }
        }

        return false;
    }

    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        visited.assign(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (!visited[i][j]) {
                    if (dfs(grid, i, j, -1, -1))
                        return true;
                }
            }
        }

        return false;
    }
};