#include<bits/stdc++.h>
using namespace std;

int dp[1000][1000];
/*
int findWays(int faces, int throws, int sum)    // O(throws*sum)
{
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;
    for(int i=1;i<=throws;i++)
    {
        for(int j=i;j<=sum;j++)
        {
            dp[i][j] = dp[i][j-1] + dp[i-1][j-1];
            if(j-faces-1 >= 0)
                dp[i][j] -= dp[i-1][j-faces-1];
        }
    }
    return dp[throws][sum];
}
*/
int findWays(int faces, int throws, int sum)    //  O(throws*faces)
{
//    if(!throws)
//        return sum<=0? 1:0;   // if we need no of ways to get at lest sum or more // then next 2 if is not needed

    if(!sum  && !throws)
        return 1;
    if(sum<0 || !throws)
        return 0;
    if(dp[throws][sum] != -1)
        return dp[throws][sum];

    int ans=0;
    for(int i=1;i<=faces;i++)
        ans += findWays(faces, throws-1, sum-i);

    return dp[throws][sum] = ans;
}

int main()
{
    memset(dp,-1,sizeof(dp));   //for rec
    int n,m,sum;
    cin>>n>>m>>sum; // n = dices/throws, m= faces
    cout<<findWays(m, n, sum)<<endl;
}
