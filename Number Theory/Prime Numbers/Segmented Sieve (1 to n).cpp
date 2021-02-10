#include<bits/stdc++.h>
using namespace std;

vector<int> prime;

void bitWiseSieve(int n)
{
    int notprime[n>>6];
    memset(notprime, 0, sizeof(notprime));
    prime.emplace_back(2);
    cout<<2<<" ";

    for(int i=3;i*i<=n;i+=2)
        if( !(notprime[i>>6] & (1 << ((i>>1)&31)) ) )
            for(int j=i*i; j<=n; j+=i<<1)
                notprime[j>>6] |= (1 << ((j>>1)&31));

    for(int i=3;i<=n;i+=2)
        if( !(notprime[i>>6] & (1 << ((i>>1)&31)) ) )
        {
            prime.emplace_back(i);
            cout<<i<<" ";
        }
}

void segmented_sieve(int n)
{
    int rt=sqrt(n)+1;
    bitWiseSieve(rt);
    int low=rt,high=rt*2,sz=prime.size();
    while(low<n)
    {
        bool notprime[rt+1]={false};
        if(high>=n)
            high=n;
        for(int i=0;i<sz;i++)
        {
            int lim=(low/prime[i])*prime[i];
            if(lim<low)
                lim+=prime[i];
            for(int j=lim;j<high;j+=prime[i])
                notprime[j-low]=true;
        }
        for(int i=low;i<high;i++)
            if(notprime[i-low]==false)
                cout<<i<<" ";
        low+=rt;
        high+=rt;
    }
    cout<<endl;
}

int main()
{
    int n;
    cin>>n;
    segmented_sieve(n+1);
}
