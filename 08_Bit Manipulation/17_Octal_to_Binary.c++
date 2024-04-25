/*
################################################ Solution ####################################################

Approach: 
For Octal to Binary Conversion, we will first convert Octal Number System to Decimal Number System and then convert Decimal Number System to Binary Number System.

For Octal to Decimal Conversion:
We will take every digit of the number and multiply it with 8 raised to power i which will increase by 1 when we move to the next digit and then add it to sum. This task is repeated until n becomes 0.

TC: O(log n), SC:O(1)
*/


#include <bits/stdc++.h>

using namespace std;

int octalToDecimal(int octal)
{
    int dec = 0;
    int i = 0;
    while (octal != 0)
    {
        int digit = octal % 10;
        dec += digit * pow(8, i);
        i++;
        octal = octal / 10;
    }
    return dec;
}

int decimalToBinary(int dec)
{
    float bin = 0;
    int i = 0;
    while (dec != 0)
    {
        int LSB = dec & 1;
        bin = (float)(LSB * pow(10, i)) + bin;
        dec = dec >> 1;
        i++;
    }
    return bin;
}

int main()
{
    int octal;
    cout<<"Enter a octal number"<<endl;
    cin >> octal;
    int decimal = octalToDecimal(octal);
    cout << "Decimal: " << decimal<<endl;
    cout<<"Binary: "<<decimalToBinary(decimal);
    return 0;
}