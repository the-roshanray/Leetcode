public class Solution {
    public int[] RearrangeArray(int[] nums) {
       int n = nums.Length;
        int[] result = new int[n];;
        int evenPlace = 0;
        int oddPlace = 1;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] >= 0)
            {
                result[evenPlace] = nums[i];
                evenPlace += 2;
            }

            else
            {
                result[oddPlace] = nums[i];
                oddPlace += 2;
            }
        }
        return result; 
    }
}