class Solution {
public:
    bool isPossible(int day, vector<int>& bloomDays, int m, int k) {
        int count = 0;
        int bouquets = 0;

        for (int i = 0; i < bloomDays.size(); i++) {
            if (bloomDays[i] <= day) {
                count++;

                if (count == k) {
                    bouquets++;
                    count = 0;
                }
            } else {
                count = 0;
            }
        }

        return bouquets >= m;
    }
    int minDays(vector<int>& bloomDays, int m, int k) {
        long long requiredFlowers = 1LL * m * k;

        if (requiredFlowers > bloomDays.size())
            return -1;

        int low = *min_element(bloomDays.begin(), bloomDays.end());
        int high = *max_element(bloomDays.begin(), bloomDays.end());

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (isPossible(mid, bloomDays, m, k))
                high = mid;
            else
                low = mid + 1;
        }

        return low;
    }
};