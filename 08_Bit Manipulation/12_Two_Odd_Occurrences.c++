/*
You are given an array 'arr'of size 'n'. It contains an even number of occurrences for all numbers except two numbers.
Find those two numbers which have odd occurrences and return in decreasing order.

arr = {2, 4, 1, 3, 2, 4}, n = 6.
output: {3, 1}
*/


/*
Approach : Bit manipulation (Optimized) [same concept that we used in repeating and missing number problem]
1. Calculate xor of all the elements of the array.
2. Find the rightmost set bit of value stored in xor variable at which bits of two different numbers bound to be different.
3. Seggragate all array elements in 0 club and 1 club based on their value of bit at position bitNo. simultaneously perform xor on club 0 and club 1.
4. After step 3, now we have two numbers that have odd occurrences in club 0 and 1 respectively.
So, compare which one is greater will be return first and smaller after the greater.

TC: O(n), SC: O(1)
*/


/*
vector<int> twoOddNum(vector<int> arr){
    int xr = 0;
    for(int i=0; i<arr.size(); i++){
        xr = xr ^ arr[i];
    }

    int bitNo = 0;
    while(1){
        if( (xr & (1<<bitNo)) != 0 ) break;
        else bitNo++;
    }
    
    int zero = 0, one = 0;
    for(int i=0; i<arr.size(); i++){
        if( (arr[i] & (1<<bitNo)) != 0 ) one = one ^ arr[i];
        else zero = zero ^ arr[i];
    }

    if(zero < one) return {one, zero};
    else return {zero, one};
}
*/