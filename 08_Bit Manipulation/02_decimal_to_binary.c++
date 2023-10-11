//Decimal to Binary

/*
Approach : Using bitwise AND (&) operator [Optimal approach]

1. Initialize a variable ans to 0, and i to 0.
2. While the decimal number is not equal to zero:
3. Extract the LSB of the decimal number using the bitwise AND operator.
4. Multiply the LSB by the pow(10, i) and add it to ans.
5. Shift the decimal number by one bit to the right using the bitwise right shift operator.
Return result.

TC: O(log n), SC:O(1)
*/
#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin>>n;

    int i = 0; 
    float ans = 0;
    
    while(n!=0){
        //LSB
        int bit = n & 1;

        ans = (bit * pow(10, i)) + ans;
        n = n >> 1;
        i++;
    }

    cout<<"Decimal number: "<<ans<<endl;

    return 0;
}