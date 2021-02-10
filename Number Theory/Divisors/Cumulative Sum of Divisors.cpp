#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll CSOD(ll n)
{
    ll sum=0,i;
    for(i=2;i*i<=n;i++)
    {
        ll j=n/i;
        sum+=(j+i)* (j-i+1)/2;
        sum+=(j-i)* i;
    }
    return sum;
}

int main()
{
    ll n;
    cin>>n;
    cout<<CSOD(n)<<endl;
}

// http://rizoantoufiq.blogspot.com/2015/12/lightoj-1098-new-function.html
