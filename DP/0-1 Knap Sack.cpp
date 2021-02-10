#include<bits/stdc++.h>
using namespace std;

int n,w[105],p[105],mw,i,dp[105][1005];
/*
int knap_sack(int n, int mw)
{
    if(!n || !mw)
        return 0;
    if(dp[n][mw] != -1)
        return dp[n][mw];

    if(w[n] > mw)
        dp[n][mw] = knap_sack(n-1,mw);
    else
        dp[n][mw] = max( p[n] + knap_sack(n-1, mw-w[n]) , knap_sack(n-1, mw) );

    return dp[n][mw];
}
*/
int knap_sack(int idx, int mw)
{
    if(mw<=0 || idx>n)
        return 0;
    if(dp[idx][mw] != -1)
        return dp[idx][mw];

    if(w[idx] > mw)
        dp[idx][mw] = knap_sack(idx+1,mw);
    else
        dp[idx][mw] = max(p[idx]+ knap_sack(idx+1 , mw-w[idx]) , knap_sack(idx+1,mw));

    return dp[idx][mw];
}

int main()
{
    cin>>n>>mw;
    for(i=1;i<=n;i++)
        cin>>w[i];
    for(i=1;i<=n;i++)
        cin>>p[i];

    memset(dp,-1,sizeof(dp));
  //  cout<<"Max Price : "<<knap_sack(n,mw)<<endl;
    cout<<"Max Price : "<<knap_sack(0,mw)<<endl;
}
