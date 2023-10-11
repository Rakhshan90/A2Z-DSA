//Binary to Decimal

/*
Approach : 
1. Initialize a variable ans to 0, and i to 0.
2. While the binary number is not equal to zero:
3. Extract the least significant bit (LSB) of the binary number by perform modulo 10 to binary number bcoz here input bit number will be consider as decimal for compiler.
4. If the LSB is equal to 1, add the pow(2, i) to ans.
5. remove the processed LSB bit form the binary number by performing divide 10 to binary number.
Return result.

TC:O(log n), SC:O(1)
*/
#include<bits/stdc++.h>

using namespace std;

int main(){
    
    int n;
    cin>>n;
    int i=0, ans = 0;
    while(n!=0){
        int digit = n % 10;
        if(digit == 1) ans = ans + pow(2, i);
        i++;
        n = n / 10;
    }
    cout<<"Decimal :"<<ans<<endl;


    return 0;
}