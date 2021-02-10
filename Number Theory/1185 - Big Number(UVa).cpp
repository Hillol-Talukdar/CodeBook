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

int digits[10000005],x,T;

void find_digits(int n)
{
    double dgts=0.0;
    for(int i=1;i<=n;i++)
    {
        dgts+=log10(i);
        digits[i]=(int) dgts+1;
    }
}

int main()
{
    find_digits(10000000);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&x);
        printf("%d\n",digits[x]);
    }
}


