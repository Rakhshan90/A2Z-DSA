/*
Example 1:
Input: 7824
Output: seven thousand eight hundred twenty four

Example 2:
Input: 370
Output: three hundred seventy
*/

/*
Approach: 

Case 1:  When a single digit is present

Case 2: When two digits are present

Subcases for 2 digits will be

-> having tens place as 1

-> having tens place as any other number other than 1 and 0

Case 3: When three digits are present

Just add hundred to hundredth place number, the further process will remain same as 2 digit number

Case 4: When 4 digits are present

Just add thousand to thousand place and further process will remain same as 3 digit number.

TC: O (n), SC: O(1)
*/

#include <bits/stdc++.h>

using namespace std;

void NumbersToWords(string s)
{
    string singleDigit[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    string doubleDigit[] = {
        "ten",
        "eleven",
        "twelve",
        "thirteen",
        "fourteen",
        "fifteen",
        "sixteen",
        "seventeen",
        "eighteen",
        "nineteen",
    };
    string tensMultiple[] = {"", "", "twenty", "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    string tensPower[] = {"hundred", "thousand"};

    int len = s.length();
    if (len == 0)
    {
        cout << " ";
        return;
    }
    else if (len == 1)
    {
        cout << singleDigit[s[0] - '0'];
        return;
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (len > 2)
        {
            if (s[i] - '0' != 0)
            {
                cout << singleDigit[s[i] - '0'] << " ";
                cout << tensPower[len - 3] << " ";
            }
            len--;
        }
        else
        {
            if (s[i] - '0' == 1)
            {
                cout << doubleDigit[s[i + 1] - '0'] << " ";
                return;
            }
            else if (s[i] - '0' != 0)
            {
                cout << tensMultiple[s[i] - '0'] << " ";
                if (s[i + 1] - '0' != 0)
                    cout << singleDigit[s[i + 1] - '0'];
                return;
            }
            else if (s[i] - '0' == 0)
            {
                cout << singleDigit[s[i + 1] - '0'];
                return;
            }
        }
    }
}
int main()
{
    string s;
    cin >> s;
    NumbersToWords(s);
    return 0;
}