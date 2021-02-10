#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b)
{
    if(!a)
        return b;
    return gcd(b%a,a);
}

int main()
{
    int a,b;
    cin>>a>>b;
    if(__gcd(a,b)==0)
        cout<<"NO output"<<endl;
    else
        cout<<(a*b)/__gcd(a,b)<<endl;
}
