class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size());
        int evenIndex = 0;
        int oddIndex = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >= 0) {
                ans[evenIndex] = nums[i];
                evenIndex = evenIndex + 2;
            } else {
                ans[oddIndex] = nums[i];
                oddIndex = oddIndex + 2;
            }
        }
        return ans;
    }
};