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
    int a[1000],n,i,ans,g;
    bool flag=false;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    ans=a[0];
    for(i=1;i<n;i++)
    {
        g=__gcd(ans,a[i]);  //g=gcd(ans,a[i]);
        if(!g)
        {
            flag=true;
            break;
        }
        ans*=a[i]/g;
    }
    if(flag)
        cout<<"Infinity"<<endl;
    else
        cout<<ans<<endl;
}
