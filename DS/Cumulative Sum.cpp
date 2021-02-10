#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[1000],sum[1000],n,ans=0,i;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
        ans+=a[i];
        sum[i]=ans;
    }
    for(i=0;i<n;i++)
        cout<<sum[i]<<" ";
    cout<<endl;
}
