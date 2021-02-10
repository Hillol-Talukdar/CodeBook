#include<bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll> prime;
/*
void sieve(ll n)
{
    bool notprime[n+5]={false};
    prime.emplace_back(2);
    for(int i=3;i*i<=n;i+=2)
        if(!notprime[i])
            for(int j=i*i;j<=n;j+=i<<1)
                notprime[j]=true;
     for(int i=3;i<=n;i+=2)
        if(!notprime[i])
            prime.emplace_back(i);

}*/

void bitWiseSieve(ll n)
{
    int notprime[n>>6];
    memset(notprime, 0, sizeof(notprime));
    prime.emplace_back(2);

    for(int i=3;i*i<=n;i+=2)
        if( !(notprime[i>>6] & (1 << ((i>>1)&31)) ) )
            for(int j=i*i; j<=n; j+=i<<1)
                notprime[j>>6] |= (1 << ((j>>1)&31));

    for(int i=3;i<=n;i+=2)
        if( !(notprime[i>>6] & (1 << ((i>>1)&31)) ) )
            prime.emplace_back(i);
}

void segmented_sieve(ll n, ll m)
{
    ll rt=sqrt(m)+1;
    bitWiseSieve(rt);
    ll sz=prime.size();
    bool notprime[m-n+1]={false};
    if(n==1)
        notprime[0]=true;
    for(ll i=0;i<sz;i++)
    {
        ll p=prime[i];
        ll base=(n/p)*p;
        if(base<n)
            base+=p;
        for(ll j=base;j<=m;j+=p)
            notprime[j-n]=true;
        if(base==p)
            notprime[base-n]=false;
    }
    for(ll i=0;i<m-n+1;i++)
        if(!notprime[i])
            cout<<i+n<<" ";
    cout<<endl;
}

int main()
{
    ll n,m;
    cin>>n>>m;
    if(n>m)
        swap(n,m);
    segmented_sieve(n,m);
}
