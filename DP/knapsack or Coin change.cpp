#include<bits/stdc++.h>
using namespace std;

int n,m,d,dp[205][100][100],a[205];

int knap_sack()
{
    memset(dp,0,sizeof(dp));
    dp[0][0][0]=1;      // index, how may items/coin taken , sum/total
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            for(int k=0;k<d;k++)
            {
                int temp = (k+a[i])%d;
                if(temp<0)      // for handling negative numbers
                    temp+=d;

                dp[i][j][k] += dp[i-1][j][k];
                if(j)
                    dp[i][j][k] += dp[i-1][j-1][temp];
            }
        }
    }
    return dp[n][m][0];
}
/*
int knap_sack(int idx, int cnt, int sum)
{
    if(cnt==m)
    {
        if(sum==0)
            return 1;
        return 0;
    }
    if(idx>=n)
        return 0;

    ll &ret = dp[idx][cnt][sum];
    if(ret!=-1)
        return ret;

    ll taken=0, not_taken=0;
    ll temp = (sum+a[idx])%d;
    if(temp<0)
        temp+=d;

    taken = knap_sack(idx+1, cnt+1, temp);
    not_taken = knap_sack(idx+1, cnt, (sum)%d);
    return ret = taken + not_taken;
}
*/

int main()
{
    cin>>n>>m>>d;   // take m numbers from n numbers which sum is divisible by d
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<knap_sack()<<endl;

//    memset(dp,-1,sizeof(dp));
//    cout<<knap_sack(0,0,0)<<endl;
}
