//Print 1 to N using recursion using tail recursion
/*
#include<bits/stdc++.h>

using namespace std;
void print(int n, int i){
    if(i>n) return;

    cout<<i<<endl;
    print(n, i+1);
}
int main(){
    int n=5;
    cin>>n;
    print(n, 1);
    return 0;
}*/

// Print N to 1 using recursion using head recursion (Backtracking)
#include<bits/stdc++.h>

using namespace std;
void print(int n, int i){
    if(i>n) return;

    print(n, i+1);
    cout<<i<<endl;
}
int main(){
    int n;
    cin>>n;
    print(n, 1);
    return 0;
}