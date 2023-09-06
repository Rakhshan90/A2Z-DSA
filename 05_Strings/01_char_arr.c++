#include<iostream>
#include<string.h>
using namespace std;
char toLowerCase(char ch){
    if(ch>= 'a' && ch<='z'){
        return ch;
    }
    else{
        char temp = ch - 'A' + 'a';
        return temp;
    }
}
bool isPalindrome(char name[], int n){
    int s=0; 
    int e=n-1;
    while(s<e){
        if(toLowerCase(name[s])!=toLowerCase(name[e])){
            return false;
        }
        else{
            s++;
            e--;
        }
    }
    return true;
}
void reverse(char name[], int n){
    int s=0;
    int e=n-1;
    while(s<e){
        swap(name[s], name[e]);
        s++;
        e--;
    }
}
int getLength(char name[]){
    int count =0;
    for(int i=0; name[i]!='\0'; i++){
        count++;
    }
    return count;
}

char getMaxOcc(string s){
    int arr[26] = {0};

    //create an array of count of characters
    for(int i=0; i<s.length(); i++){
        char ch = s[i];
        int count = 0;
        count = ch - 'a';
        arr[count]++;
    }
    // find max occurring character
    int maxi =-1, ans =0;
    for(int i=0; i<26; i++){
        if(maxi<arr[i]){
            ans = i;
            maxi = arr[i];
        }
    }
    char finalAns = 'a' + ans;
    return finalAns;
}
int main(){
    // char name[30];
    // cout<<"Enter Your name"<<endl;
    // cin>>name;
    // int len = getLength(name);
    // cout<<"Your name's length is: "<<len<<endl;
    // reverse(name, len);
    // cout<<"Your name is: "<<name<<endl;
    // if(isPalindrome(name, len)){
    //     cout<<"It is a Palindrome"<<endl;
    // }
    // else{
    //     cout<<"Not a palindrome"<<endl;
    // }
    // cout<<"toLowerCase: "<<toLowerCase('A')<<endl;
    // cout<<"toLowerCase: "<<toLowerCase('a')<<endl;

    string s;
    cin>>s;
    cout<<getMaxOcc(s)<<endl;
    return 0;
}