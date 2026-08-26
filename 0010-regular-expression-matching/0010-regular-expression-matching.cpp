class Solution {
public:
    vector<vector<int>> dp;

    bool solve(int i, int j, string& s, string& p) {
        if (j == p.size())
            return i == s.size();

        if (dp[i][j] != -1)
            return dp[i][j];

        bool firstMatch =
            (i < s.size() && (s[i] == p[j] || p[j] == '.'));

        if (j + 1 < p.size() && p[j + 1] == '*') {
            return dp[i][j] =
                       (solve(i, j + 2, s, p) ||     
                        (firstMatch && solve(i + 1, j, s, p)));
        }

        return dp[i][j] =
                   (firstMatch && solve(i + 1, j + 1, s, p));
    }

    bool isMatch(string s, string p) {
        dp.resize(s.size() + 1, vector<int>(p.size() + 1, -1));
        return solve(0, 0, s, p);
    }
};