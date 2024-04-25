/*
########################################### Solution #############################################
Approach: 
For Decimal to Octal Conversion, we will divide the given number by 8 ( Since Octal Numbers System has 8 digits in use ) repeatedly, and its remainder will be stored till the number becomes zero.

 Let us take an example for 136

Step 1: Divide 136 by 8, the remainder will be 0 and now n becomes 17.

Step 2: Now divide 17 by 8, the remainder will be 1 so our ans till now becomes 10 and n becomes 2

Step 3: Divide 2 by 8, the remainder will be 2, so the answer till now becomes 210 and n becomes 0 

Step 4: since n becomes 0, so print the answer i.e. 210 which is the octal equivalent of the decimal.

TC: O(log n), SC: O(1)
*/

#include<bits/stdc++.h>

using namespace std;

int decimalToOctal(int dec){
    float octal = 0;
    int i=0;
    while(dec != 0){
        int rem = dec % 8;
        octal += (float)(rem * pow(10, i)); // octal = (rem * pow(10, i)) + octal
        dec = dec / 8;
        i++;
    }
    return octal;
}

int main(){
    int decimal;
    cout<<"Enter a decimal number: ";
    cin >> decimal;
    cout<<"Octal number: "<<decimalToOctal(decimal)<<endl;
    return 0;
}