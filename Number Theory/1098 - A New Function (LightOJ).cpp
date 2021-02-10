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

ll n,i,T,cs=1;

ll CSOD()
{
    ll sum=0;
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
    cin>>T;
    while(T--)
    {
        cin>>n;
        cout<<"Case "<<cs++<<": "<<CSOD()<<endl;
    }
}

// http://rizoantoufiq.blogspot.com/2015/12/lightoj-1098-new-function.html
