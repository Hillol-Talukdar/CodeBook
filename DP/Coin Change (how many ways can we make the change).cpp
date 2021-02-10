#include<bits/stdc++.h>
using namespace std;
/*
int coin_change(int a[], int n, int tot)
{
    int dp[n+5][tot+5];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<=n;i++)
        dp[i][0] = 1;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=tot;j++)
        {
            if(a[i-1] > j)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = dp[i][j-a[i-1]] + dp[i-1][j];
        }
    }
    return dp[n][tot];
}
*/

int coin_change(int a[], int n, int tot)
{
    int dp[tot+5]={0};
    dp[0] = 1;
    for(int i=0; i<n; i++)
        for(int j=a[i]; j<=tot; j++)
            dp[j] += dp[j-a[i]];

    return dp[tot];
}

void coin_change_finit(int a[],int n, int mx_value, int mx_coins)
{
    int dp[mx_value+1][mx_coins+1];
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(int i=0;i<n;i++)
        for(int j=mx_value;j>=a[i];j--)
            for(int k=mx_coins;k>=1;k--)   //total coin taken
                dp[j][k] += dp[j-a[i]][k-1];
}

/*
int a[1005],n,tot,cntCoinsa[1005],dp[1005][1005];

int coin_change_finit(int tot, int idx)
{
   if(idx==n)
       return (!tot) ? 1 : 0;
   if(!tot)
       return 1;
   if(tot<0)
       return 0;

   if(dp[tot][idx] != -1)
       return dp[tot][idx];

   int res = 0;
   for(int i=0;i<=cntCoins[idx];i++)
       res = res + coin_change_finit(tot-a[idx]*i, idx+1);

   dp[tot][idx] = res;
   return res;
}
*/

int main()
{
    int a[1005],n,tot,cntCoins[1005];
   // memset(dp,-1,sizeof(dp));
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cin>>tot;

    cout<<"The number of ways we can make the change : "<<coin_change(a,n,tot)<<endl;
}
