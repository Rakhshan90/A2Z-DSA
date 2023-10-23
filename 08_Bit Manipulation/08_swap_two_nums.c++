/*
You are given two numbers 'a'and 'b'as input. You must swap the values of 'a' and 'b'. 
*/

/*
Approach 1: Using extra variables

void swapNumber(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}
*/

/*
Approach 2: Using in-built C++ swap function

#include<bits/stdc++.h>
void swapNumber(int &a, int &b) {
	swap(a, b);
}
*/

/*
Approach 3: Using bitwise xor operator. [Important]

#include<bits/stdc++.h>
void swapNumber(int &a, int &b) {
	a = a ^ b;
	b = a ^ b; // b = a
	a = a ^ b; // a = b	
}
*/