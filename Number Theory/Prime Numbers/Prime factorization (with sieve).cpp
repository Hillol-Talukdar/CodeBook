#include<bits/stdc++.h>
using namespace std;

vector<int> prime;
int n,rt;

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

void prime_factors()
{
    int i,sz=prime.size(),j,count=0,k=0;;
    for(i=prime[k]; i*i<=n && k<sz; i=prime[++k])
    {
        while(!(n%i))
        {
            count++;
            n/=i;
            cout<<i<<" ";
        }
    }
    if(n>1)
    {
        count++;
        cout<<n;
    }

    cout<<endl;
    cout<<"Number of Prime Factors : "<<count<<endl;
}

int main()
{
    cin>>n;
    rt=sqrt(n);
    bitWiseSieve(rt+1);
    prime_factors();
}
