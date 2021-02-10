#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define in_txt  freopen("input.txt", "r", stdin)
#define out_txt  freopen("output.txt", "w", stdout)
#define FastRead     ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pi acos(-1)
#define pb push_back
#define pp pop_back
#define isvowel(ch) ((ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')||(ch=='A'|| ch=='E' || ch=='I'|| ch=='O'|| ch=='U'))
#define mem(a,b)     memset(a,b,sizeof(a))

ll T,n,cs=1;
vector<ll> prime;
bool notprime[10000005]={false};

void sieve(ll n)
{

    ll i,j;
    prime.push_back(2);
    for(i=3;i*i<=n;i+=2)
        if(notprime[i]==false)
            for(j=i*i;j<=n;j+=i)
                notprime[j]=true;
    for(i=3;i<=n;i+=2)
        if(notprime[i]==false)
            prime.push_back(i);

}

ll prime_factors()
{
    ll i,sz=prime.size(),j,k=0,ans=1;
    for(i=prime[k]; i<=n && k<sz; i=prime[++k])
    {
        ll count=0;
        while(!(n%i))
        {
            count++;
            n/=i;
        }
        if(k)
            ans*=count+1;
    }
    if(n>1)
        ans*=2;
    return ans-1;
}

int main()
{
    sieve(10000000);
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld",&n);
        printf("Case %lld: %lld\n",cs++,prime_factors());
    }
}

