#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b)
{
    if(!a)
        return b;
    return gcd(b%a,a);
}

int main()
{
    int a[1000],n,ans,i;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    ans=a[0];
    for(i=1;i<n;i++)
        ans=__gcd(ans,a[i]); //ans=gcd(ans,a[i]);

    cout<<ans<<endl;
}
