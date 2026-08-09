class Solution
{
public:
    int secondHighest(string s)
    {
        if (s.empty())
            return -1;

        int largest = INT_MIN;
        int secondLargest = INT_MIN;

        for (int i = 0; i < s.length(); i++)
        {
            if (isdigit(s[i]))
            {
                int digit = s[i] - '0';

                if (digit > largest)
                {
                    secondLargest = largest;
                    largest = digit;
                }
                
                else if (digit != largest && digit > secondLargest)
                {
                    secondLargest = digit;
                }
            }
        }
        return (secondLargest == INT_MIN) ? -1 : secondLargest;
    }
};