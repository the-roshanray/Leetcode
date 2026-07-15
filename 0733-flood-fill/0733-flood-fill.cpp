class Solution {
public:
    void dfsHelper(int row, int col, vector<vector<int>>& image, int oldColor,
                   int newColor) {
        int n = image.size();
        int m = image[0].size();

        if (row < 0 || row >= n || col < 0 || col >= m ||
            image[row][col] != oldColor)
            return;

        image[row][col] = newColor;
        dfsHelper(row + 1, col, image, oldColor, newColor);
        dfsHelper(row, col + 1, image, oldColor, newColor);
        dfsHelper(row - 1, col, image, oldColor, newColor);
        dfsHelper(row, col - 1, image, oldColor, newColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int oldColor = image[sr][sc];
        if (oldColor == color)
            return image;

        dfsHelper(sr, sc, image, oldColor, color);
        return image;
    }
};