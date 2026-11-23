public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        Dictionary<int, int>map = new Dictionary<int, int>();
        int n = nums.Length;
        for(int i = 0; i<n; i++){
            int complement = target - nums[i];
            if(map.ContainsKey(complement))
                return new int[]{map[complement],i};
            map[nums[i]]= i;    
        }
        return new int[]{-1, -1};
    }
}