/*
Problem statement: You are given an array of 'N' integers where each integer value is
between '1 ' and 'N'. Each integer appears exactly once except for "P', which appears exactly twice, and "Q', which is missing.
Your task is to find 'P' and 'Q' and return them respectively.
*/

/*
Approach 1: Using hashing
We will store the frequency of each element. Now the element with frequency 2 will be the repeating number, and the element with frequency 0 will be the missing number. 
TC: O(n), SC:O(n)
*/
/*
Approach 2: Using bitwise xor(^)
1. Find xor of missing and repeating number by xoring all elements of array and range [1, n]
2. Find bitNo. of xor at which bits of different numbers bound to be different. so find defferentiating bitNo. from right in xr. 
3. Seggragate all array elements and range elements in 0 club and 1 club based on their value of bit at position bitNo.  simultaneously perform xor on club 0 and club 1.
4. Now iterate over the arr to cross check which number is repeating and missing of club 0 and club 1.

TC:O(n), SC:O(1)
*/
/*
vector<int> findMissingRepeatingNumbers(vector < int > a) {
    int n = a.size();
    //step 1: XOR of all array elements and range elements
    int xr = 0;
    for(int i=0; i<n; i++){
        xr = xr ^ a[i];
        xr = xr ^ (i+1);
    }

    //step 2: find differentiating bitNo. from the right in xr
    int bitNo = 0;
    while(1){
        if((xr & (1<<bitNo)) != 0) break;
        else bitNo++;
    }

    //step 3: seggragate all array elements and range elements in 0 and 1 club based on their bitNo.
    int zero = 0, one = 0;
    for(int i=0; i<n; i++){
        if((a[i] & (1<<bitNo)) != 0) one = one ^ a[i];
        else zero = zero ^ a[i];
    }
    for(int i=1; i<=n; i++){
        if((i & (1<<bitNo)) != 0) one = one ^ i;
        else zero = zero ^ i;
    }
    //step 4: Now iterate over the arr to cross check which number is repeating and missing
    int cnt = 0;
    for(int i=0; i<n; i++){
        if(a[i] == zero) cnt++;
    }
    if(cnt == 2) return {zero, one};
    else return {one, zero};
}
*/