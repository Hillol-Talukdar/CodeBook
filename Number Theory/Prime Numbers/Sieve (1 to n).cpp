#include<bits/stdc++.h>
using namespace std;

vector<int> prime;

void bitWiseSieve(int n)
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

void sieve(int n)
{
    int i,j;
    bool notprime[n+1]={false};
    prime.emplace_back(2);

    for(i=3;i*i<=n;i+=2)
        if(!notprime[i])
            for(j=i*i;j<=n;j+=i<<1)
                notprime[j]=true;
    for(i=3;i<=n;i+=2)
        if(!notprime[i])
            prime.emplace_back(i);
}

int main()
{
    int n;
    scanf("%d",&n);
    sieve(n);
    bitWiseSieve(n);
    for(auto it:prime)
        cout<<it<<endl;
}
