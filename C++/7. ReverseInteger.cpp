/*
Given a 32-bit signed integer, reverse digits of an integer.

Note:
Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

Example 1:

Input: x = 123
Output: 321

*/

class Solution
{
public:
    int reverse(int x)
    {
        if (!x)
            return 0;
        while (x % 10 == 0)
            x /= 10;
        long long sum = 0;
        while (x)
        {
            sum = sum * 10 + x % 10;
            x /= 10;
        }
        int res = sum;
        if (res == sum)
            return res;
        else
            return 0;
    }
};