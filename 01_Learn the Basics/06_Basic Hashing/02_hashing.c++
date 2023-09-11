//find frequencies of each character in a given string s. All the characters are in lower case

#include<bits/stdc++.h>

using namespace std;

void frequency(string s){
    //hashing
    int hash[26] = {0};
    for(int i=0; i<s.size(); i++){
        //ch - 'a' it gives some value that corresponding to index of the hash array
        hash[s[i]-'a']++;
    }
    
    //fetch
    for(int i=0; i<26; i++){
        cout<<i<<" "<<hash[i]<<endl;
    }
    
}
int main(){
    string s = "hello";
    frequency(s);

    return 0;
}