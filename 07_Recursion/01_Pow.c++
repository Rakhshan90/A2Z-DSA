/*
Approach:  Using Binary Exponentiation
1. Initialize ans as 1.0  and store a duplicate copy of n i.e nn using to avoid overflow
2. Check if nn is a negative number, in that case, make it a positive number.
3. Keep on iterating until nn is greater than zero, now if nn is an odd power then multiply x with ans ans reduce nn by 1. Else multiply x with itself and divide nn by two.
4. Now after the entire binary exponentiation is complete and nn becomes zero, check if n is a negative value we know the answer will be 1 by and.

TC:O(log n), SC:O(1)
*/
/*
double myPow(double x, int n) {
        long long nn = n;
        if(nn<0) nn = -1*nn;
        double ans = 1.0;
        while(nn){
            if(nn%2==1){
                ans = ans*x;
                nn=nn-1;
            }
            else{
                x=x*x;
                nn=nn/2;
            }
        }
        if(n<0) ans = (double) (1.0)/(double)(ans);
        return ans;
    }
*/

/*
Approach : same logic but by using functional recursion
TC: O(log n), SC:O(log n)
*/
/*
double myPow(double x, int n) {
        long long nn = n;
        if(nn==0) return 1;
        if(nn<0){
            nn = -1*nn;
            x = 1/x;
        }
        if(nn%2==0) return myPow(x*x, nn/2);
        else return x*myPow(x, nn-1);
    }
*/