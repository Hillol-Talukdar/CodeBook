#include<bits/stdc++.h>
using namespace std;

int maxIncSubarr(int a[], int n)
{
    int pre[n]={0}, suf[n]={0}, ans=0 , len=1;;
    pre[0] = suf[n-1] = 1;

    for(int i=1;i<n;i++)
        pre[i] = (a[i-1]<a[i]) ? pre[i-1]+1 : 1;

    for(int i=n-2;i>=0;i--)
        suf[i] = (a[i]<a[i+1]) ? suf[i+1]+1 : 1;

    for(int i=1;i<n;i++)
    {
        (a[i-1] < a[i]) ? len++ : len=1;
        ans = max(ans, len);
    }
    for(int i=1;i<=n-2;i++)
        if(a[i-1] < a[i+1])
            ans = max(pre[i-1] + suf[i+1], ans);

    return ans;
}

int main()
{
    int a[1005],n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<maxIncSubarr(a, n)<<endl;
}

