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
#define isvowel(ch) ((ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')||(ch=='A'|| ch=='E' || ch=='I'|| ch=='O'|| ch=='U'))
#define mem(a,b)     memset(a,b,sizeof(a))


int main()
{
    ll T,n;
    cin>>T;
    while(T--)
    {
        cin>>n;
        ll ans=0,x=5,power=1;
        while(x<=n)
        {
            ans+=n/x;

            double temp=pow(5,++power);
            x= (ll) temp;
        }
        cout<<ans<<endl;
    }
}
