#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define in_txt  freopen("input.txt", "r", stdin)
#define out_txt  freopen("output.txt", "w", stdout)
#define FastRead     ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pi acos(-1)
#define pf push_front
#define pb push_back
#define ppf pop_front
#define ppb pop_back
#define FI first
#define SE second
#define isvowel(ch) ((ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')||(ch=='A'|| ch=='E' || ch=='I'|| ch=='O'|| ch=='U'))
#define mem(a,b)     memset(a,b,sizeof(a))

#define for0(i, n) for(int i=0; i<n; i++)
#define for1(i, n) for(int i=1; i<=n; i++)
#define fr(i,start, till) for(int i=start; i<=till; i++)

#define cin0(n, ara) for(int i=0; i<n; i++) {cin>>ara[i];}
#define cin1(n, ara) for(int i=1; i<=n; i++) {cin>>ara[i];}

#define si(n) scanf("%d", &n)
#define sii(n, m) scanf("%d %d", &n, &m)
#define siii(n, m, k) scanf("%d %d %d", &n, &m, &k)
#define siiii(n, m, k, o) scanf("%d %d %d %d", &n, &m, &k, &o)

#define sl(n) scanf("%lld", &n)
#define sll(n, m) scanf("%lld %lld", &n, &m)
#define slll(n, m, k) scanf("%lld %lld %lld", &n, &m, &k)
#define sllll(n, m, k, o) scanf("%lld %lld %lld %lld", &n, &m, &k, &o)

#define sd(n) scanf("%lf", &n)
#define sdd(n, m) scanf("%lf %lf", &n, &m)
#define sddd(n, m, k) scanf("%lf %lf %lf", &n, &m, &k)
#define sdddd(n, m, k, o) scanf("%lf %lf %lf %lf", &n, &m, &k, &o)

#define scs(s) scanf("%s",s)
#define scss(s, s1) scanf("%s %s",s, s1)
#define scsp(s) scanf(" %[^\n]",s)

ll n,x,cnt=0;

ll devisors(ll n)
{
    int count=0;
    for(ll i=1;i*i<=n;i++)
    {
        if(!(n%i))
        {
            ll cur=n/i;
            count++;
            if(i!=cur)
                count++;
        }
    }
    return count;
}

int main()
{
    FastRead;
    cin>>n;
    for0(i,n)
    {
        cin>>x;
        if(!i)
            cnt=x;
        else
            cnt = __gcd(cnt , x);
    }
    cout<<devisors(cnt)<<endl;
}
