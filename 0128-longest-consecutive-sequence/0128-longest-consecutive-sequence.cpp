class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest = 0;
        unordered_set<int> set(nums.begin(), nums.end());
        for (auto num : set) {
            if (set.find(num - 1) == set.end()) {
                int current = num;
                int length = 1;

                while (set.find(current + 1) != set.end()) {
                    current++;
                    length++;
                }
                longest = max(longest, length);
            }
        }
        return longest;
    }
};