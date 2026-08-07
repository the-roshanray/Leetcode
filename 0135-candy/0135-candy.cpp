class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n <= 1) return n;

        int candies = 1;
        int up = 0, down = 0;
        int oldSlope = 0;

        for (int i = 1; i < n; i++) {
            int newSlope = (ratings[i] > ratings[i - 1]) ? 1 :
                           (ratings[i] < ratings[i - 1]) ? -1 : 0;

            if ((oldSlope > 0 && newSlope == 0) ||
                (oldSlope < 0 && newSlope >= 0)) {

                candies += (up * (up + 1)) / 2;
                candies += (down * (down + 1)) / 2;
                candies += max(up, down);

                up = down = 0;
            }

            if (newSlope > 0) up++;
            else if (newSlope < 0) down++;
            else candies++;

            oldSlope = newSlope;
        }

        candies += (up * (up + 1)) / 2;
        candies += (down * (down + 1)) / 2;
        candies += max(up, down);

        return candies;
    }
};