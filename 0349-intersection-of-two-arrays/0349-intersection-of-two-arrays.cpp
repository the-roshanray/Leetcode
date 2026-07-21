class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> set(nums1.begin(), nums1.end());
        unordered_set<int> ansSet;

        for (int i = 0; i < nums2.size(); i++) {
            if (set.count(nums2[i]))
                ansSet.insert(nums2[i]);
        }

        return vector<int>(ansSet.begin(), ansSet.end());
    }
};