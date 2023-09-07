#include <iostream>

using namespace std;
void print7(int n)
{
    for (int i = 1; i <= n; i++)
    {
        // spaces
        for (int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }
        // stars
        for (int j = 1; j <= 2 * i - 1; j++)
        {
            cout << "*";
        }
        // spaces
        for (int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }

        cout << endl;
    }
}
void print8(int n)
{
    for (int i = 0; i < n; i++)
    {
        // spaces
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        // stars
        for (int j = 0; j < 2*n - (2*i+1); j++)
        {
            cout << "*";
        }
        // spaces
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }

        cout << endl;
    }
}
void print10(int n){
    for(int i=1; i<=2*n-1; i++){
        int stars = i;
        if(i>n) stars = 2*n-i;
        for(int j=1; j<=stars; j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}
void print11(int n){
    int start = -1;
    for(int i=1; i<=n; i++){
        if(i%2==1) start = 1;
        else start = 0;
        for(int j=1; j<=i; j++){
            cout<<start<<" ";
            start = 1 - start;
        }
        cout<<endl;
    }
}
void print12(int n){
    for(int i=1; i<=n-1; i++){
        //numbers
        for(int j=1; j<=i; j++){
            cout<<j;
        }
        //spaces
        for(int j=1; j<=2*n-(2*i+2); j++){
            cout<<" ";
        }
        //numbers
        for(int j=i; j>=1; j--){
            cout<<j;
        }
        cout<<endl;
    }
}
void print13(int n){
    int cnt=1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout<<cnt<<" ";
            cnt++;
        }
        cout<<endl;
    }
}
void print14(int n){
    for(int i=1; i<=n; i++){
        for(char ch='A'; ch<'A'+i; ch++){
            cout<<ch;
        }
        cout<<endl;
    }
}
void print15(int n){
    for(int i=1; i<=n; i++){
        for(char ch='A'; ch<'A'+n-i+1; ch++){
            cout<<ch;
        }
        cout<<endl;
    }
}
void print16(int n){
    for(int i=0; i<n; i++){
        char ch = 'A'+i;
        for(int j=0; j<=i; j++){
            cout<<ch;
        }
        cout<<endl;
    }
}
void print17(int n){
    for(int i=1; i<=n-1; i++){
        //spaces
        for(int j=1; j<=n-i; j++){
            cout<<" ";
        }

        //chars
        char ch='A';
        int breakPoint = (2*i-1)/2;
        for(int j=1; j<=2*i-1; j++){
            cout<<ch;
            if(j<=breakPoint) ch++;
            else ch--;
        }

        //spaces
        for(int j=1; j<=n-i; j++){
            cout<<" ";
        }
        cout<<endl;
    }
}
void print18(int n){
    for(int i=1; i<=n; i++){
        char ch='A'+n-i;
        for(int j=1; j<=i; j++){
            cout<<ch;
            ch++;
        }
        cout<<endl;
    }
}
void print19(int n){
    for(int i=1; i<=n; i++){
        //stars
        for(int j=1; j<=n-i+1; j++){
            cout<<"*";
        }
        //spaces
        for(int j=1; j<=2*i-2; j++){
            cout<<" ";
        }
        //stars
        for(int j=1; j<=n-i+1; j++){
            cout<<"*";
        }
        cout<<endl;
    }
    for(int i=1; i<=n; i++){
        //stars
        for(int j=1; j<=i; j++){
            cout<<"*";
        }
        //spaces
        for(int j=1; j<=2*n-2*i; j++){
            cout<<" ";
        }
        //stars
        for(int j=1; j<=i; j++){
            cout<<"*";
        }
        cout<<endl;
    }
    
}
void print20(int n){
    for(int i=1; i<=n; i++){
        //stars
        for(int j=1; j<=i; j++){
            cout<<"*";
        }
        //spaces
        for(int j=1; j<=2*n-2*i; j++){
            cout<<" ";
        }
        //stars
        for(int j=1; j<=i; j++){
            cout<<"*";
        }
        cout<<endl;
    }
    
    for(int i=1; i<=n-1; i++){
        //stars
        for(int j=1; j<=n-i; j++){
            cout<<"*";
        }
        //spaces
        for(int j=1; j<=2*i; j++){
            cout<<" ";
        }
        //stars
        for(int j=1; j<=n-i; j++){
            cout<<"*";
        }
        cout<<endl;
    }
}
void print21(int n){
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==0 || j==0 || i==n-1 || j==n-1){
                cout<<"*";
            }
            else cout<<" ";
        }
        cout<<endl;
    }    
}

int main()
{
    int n;
    cin>>n;
    // print7(n);
    // print8(n);
    //pattern9 is the combination of pattern7 and and pattern8

    print21(n);


    return 0;
}