class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int low = *min_element(nums.begin(), nums.end());
        int high = *max_element(nums.begin(), nums.end());

        unordered_set<int> set(nums.begin(), nums.end());

        vector<int> ans;

        for (int i = low + 1; i < high; i++)
        {
            if (!set.count(i))
                ans.push_back(i);
        }
        return ans;
    }
};