#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll countConsecutive(ll n)
{
    ll i,count=0;
    for(i=1;i*(i+1)<2*n;i++)
    {
        double x= (1.0*n-(i*(i+1))/2) / (i+1);
        if(x-(ll)x ==0.0)
            count++;
    }
    return count;
}

int main()
{
    ll n;
    cin>>n;
    cout<<countConsecutive(n)<<endl;
}
