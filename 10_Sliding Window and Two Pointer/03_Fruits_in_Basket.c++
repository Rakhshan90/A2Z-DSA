/*
Problem statement: There are 'n'fruit trees that are planted along a road. The trees are numbered
from O to n-1. The type of fruit each tree bears is represented by an integer from 1 to 'n'.
A Ninja is walking along that road. He has two baskets and wants to put the maximum number of fruits in them. The restriction is that each basket can have only one type of fruit.
Ninja can start with any tree and end at any tree, but once he has started, he cannot skip a tree i.e if he picks fruit from the tree 'i', then he has to pick fruit from tree 'i+l' before going to the tree 'i+2'. He will pick one fruit from each tree until he cannot, i.e, he will stop when he has to pick a fruit of the third type
because only two different fruits can fill both baskets.
You are given an array 'arr'. The 'i'th integer in this array represents the type of fruit tree 'i' bears. Return the maximum number of fruits Ninja can put in both baskets after satisfying all the conditions.
*/

/*
Approach : Window size with two pointer and Hashmap (Optimized)
Define variable:
i=0-> To Shrink Window Size,
j=0-> To count the frequency of each element in the hashmap.
Traverse over the Array
a)store frequency of each element one by one into the hashmap
b)while count of distinct elements is greater than 2,  
Shrink Our Window Size & update i to Shrink Window Size.
c)Update result in Every Step.
return len.

TC: O(n), SC: O(1)
*/

/*
#include<bits/stdc++.h>
int findMaxFruits(vector<int> &arr, int n) {
    int j = 0, i = 0, len = 0;
    unordered_map<int, int> count;
    while(j < n){
        count[arr[j]]++;

        // count of distinct elements is greater than 2
        while(count.size() > 2){
            count[arr[i]]--;

            if(count[arr[i]] == 0) count.erase(arr[i]);

            i++;
        }
        len = max(len, j - i + 1);

        j++;
    }
    return len;
}
*/