class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int maxRow = 0;
        int maxOnes = 0;

        for (int i = 0; i < m; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                count += matrix[i][j];
            }
            if (count > maxOnes) {
                maxOnes = count;
                maxRow = i;
            }
        }
        return {maxRow, maxOnes};
    }
};