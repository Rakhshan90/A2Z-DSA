/*
Problem statement: Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.
The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.

Return the quotient after dividing dividend by divisor.

Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−2^31, 2^31 − 1]. For this problem, if the quotient is strictly greater than 2^31 - 1, then return 2^31 - 1, and if the quotient is strictly less than -2^31, then return -2^31.
*/

/*
Approach: Bit Manipulation

The idea here is to use addition efficiently to compute the final result...
we know that division can be done using addition or subtraction...
for example 20/3 = 3+3+3+3+3+3+(2, ignored) (result is 6 times 3 hence 6)

Hence the loop is run, n times where n is our result...
To more efficiently compute this, we can reduce the loops to log n time by adding divisor everytime it is added on...

So 20/3 = 3 + 6 + 12 + (24, ignore) (curr result is 2^(3-1)=4, 3 here is number of iterations...)
left over sum, 20-12 = 8, and we repeat the process...
So 8/3 = 3 + 6 + (12, ignore) (this time result is 2^(2-1)=2, 2 here is number of iterations...)
left over sum, 8-6 = 2, since 2 is less than 3, we terminate the process...

Hence final result is 4+2 = 6

TC: O(log n), SC: O(1)
*/

/*
int divide(int dividend, int divisor) {
        //handling edge case
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        if(dividend == INT_MIN && divisor == 1) return INT_MIN;

        bool sign = (dividend >= 0) == (divisor >= 0);

        long long dd = abs(dividend), dv = abs(divisor);
        int result = 0;
        while(dd - dv >= 0){
            int cnt = 0;
            while(dd >= (dv << (1 << cnt))) cnt++;
            result += (1 << cnt);
            dd -= (dv << cnt);
        }

        return sign ? result : -result; 
    }
*/