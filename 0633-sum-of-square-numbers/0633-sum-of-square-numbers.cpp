class Solution {
public:
    bool judgeSquareSum(int n) {
         long long left = 0;
        long long right = sqrt(n);

        while (left <= right)
        {
            long long sum = left * left + right * right;
            if (sum == n)
                return true;
            else if (sum < n)
                left++;
            else
                right--;
        }

        return false;
    }
};