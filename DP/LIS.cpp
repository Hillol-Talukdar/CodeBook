#include<bits/stdc++.h>
using namespace std;
/*
int lis(int a[], int n) // O(n^2)
{
    int dp[n+5];
    dp[0]=1;
    for(int i=1;i<n;i++)
    {
        dp[i]=1;
        for(int j=0;j<i;j++)
            if(a[i]>a[j] && dp[i] < dp[j]+1)
                dp[i] = dp[j]+1;
    }
    return *max_element(dp,dp+n);
}
*/

int lis(int a[], int n)    // O(nlog(n))
{
    int dp[n+5]={0}, len=0;
    for(int i=0;i<n;i++)
    {
        auto it = lower_bound(dp,dp+len,a[i]) -dp;
        if(it == len)
            dp[len++] = a[i];
        else
            dp[it] = a[i];
    }
    return len;
}

int main()
{
    int n,a[1005];
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<"Length of lis is : "<<lis(a,n)<<endl;
}

/*
8
10 22 9 33 21 50 41 60
*/
