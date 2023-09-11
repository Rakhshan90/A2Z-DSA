// find frequencies of chars in a given string

#include <bits/stdc++.h>

using namespace std;
void frequency(string s)
{
    // unordered_map<char, int> hashMap;
    map<char, int> hashMap;
    for(int i=0; i<s.size(); i++){
        hashMap[s[i]]++;
    }

    //fetch
    for(auto it: hashMap){
        cout<<"char: "<<it.first<<", "<<"frequency :"<<it.second<<endl;
    }
}
int main()
{
    string s = "Program";
    frequency(s);
    return 0;
}