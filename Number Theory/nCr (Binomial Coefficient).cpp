#include<bits/stdc++.h>
using namespace std;

/*
int binomialCoeff(int n, int k)
{
    if(!k || k==n)
        return 1;
    return binomialCoeff(n-1, k-1) +  binomialCoeff(n-1,k);
}
*/
/*
int binomialCoeff(int n, int k) // O(n*k)
{
    int dp[n+1][k+1],i,j;
    for(i=0;i<=n;i++)
    {
        int mn=min(i,k);
        for(j=0;j<=mn;j++)
        {
            if(!j || j==i)
                dp[i][j]=1;
            else
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }
    return dp[n][k];
}
*/
/*
int binomialCoeff(int n, int k) // O(n*k)
{
    int dp[k+1];
    memset(dp,0,sizeof(dp));
    dp[0]=1;  // nC0 is 1
    for(int i=1;i<=n;i++)
        for(int j=min(i,k);j>0;j--)
            dp[j] = dp[j] + dp[j-1];
    return dp[k];
}
*/

int binomialCoeff(int n, int k) // O(r)
{
    int res=1;
    if(k > n-k) // Since C(n, k) = C(n, n-k)
        k = n-k;
    // [n * (n-1) *---* (n-k+1)] / [k * (k-1) *----* 1]
    for(int i=0;i<k;i++)
    {
        res *= (n-i);
        res /= (i+1);
    }
    return res;
}


int main()
{
    int n,k;
    cin>>n>>k;
    cout<<"nCr = "<<binomialCoeff(n,k)<<endl;
}
