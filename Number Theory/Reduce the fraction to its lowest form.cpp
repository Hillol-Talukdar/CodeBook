#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void reduceFraction(ll x, ll y)
{
    ll d=__gcd(x, y);
    x/=d;
    y/=d;
    cout<<"x = "<<x<<", y = "<<y<<endl;
}

int main()
{
    ll x,y;
    cin>>x>>y;
    reduceFraction(x, y);
}
