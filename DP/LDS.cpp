#include <bits/stdc++.h>
using namespace std;
/*
int lds(int a[], int n)
{
    int dp[n+5];
    for(int i=0;i<n;i++)
        dp[i] = 1;

    for(int i=1;i<n;i++)
        for(int j=0;j<i;j++)
            if(a[i] < a[j] && dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1;

    int len = *max_element(dp,dp+n);
    return len;
}
*/
int lds(int a[], int n)
{
    reverse(a,a+n);
    int dp[n+5]={0}, len=0;

    for(int i=0;i<n;i++)
    {
        int it = lower_bound(dp,dp+len,a[i]) - dp;
        if(it == len)
            dp[len++] = a[i];
        else
            dp[it] = a[i];

        len = max(len, it+1);
    }
    return len;
}

int main()
{
    int n,a[1005];
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<"Length of lds is : "<<lds(a,n)<<endl;
}
