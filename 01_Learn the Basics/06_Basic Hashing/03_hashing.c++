//find frequecy of a character.

#include<bits/stdc++.h>

using namespace std;

void frequency(string s, int ch){
    //hashing
    int hash[256] = {0};
    for(int i=0; i<s.size(); i++){
        //each char have its ASCII value that will stored in the corresponding index of hash arry
        hash[s[i]]++;
    }
    
    //fetch
    cout<<hash[ch];
    
}
int main(){
    string s = "hello";
    frequency(s, 'l');

    return 0;
}