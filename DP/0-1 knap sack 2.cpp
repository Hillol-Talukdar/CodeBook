#include<bits/stdc++.h>
using namespace std;

int n,mw,w[100],p[100],dp[100][100];

int knap_sack()
{
    for(int i=0; i<=n; i++)
    {
        for(int wr=0; wr<=mw; wr++)
        {
            if(!i || !wr)
                dp[i][wr]=0;
            else if(w[i]<=wr)
                dp[i][wr]=max( p[i]+ dp[i-1][wr-w[i]], dp[i-1][wr] );
            else
                dp[i][wr]=dp[i-1][wr];
        }
    }
   return dp[n][mw];
}
/*
int knap_sack(int n,int mw)
{
    if(!n || !mw)
        return 0;
    else if(w[n]>mw)
        return knap_sack(n-1 , mw);
    return max( p[n]+knap_sack(n-1, mw-w[n]) , knap_sack(n-1,mw) );
}*/

int main()
{
    int i,wr;
    cin>>n>>mw;
    for(i=1; i<=n; i++)
        cin>>w[i];
    for(i=1; i<=n; i++)
        cin>>p[i];

    cout<<"MAX PRICE : "<<knap_sack()<<endl;
   // cout<<"MAX PRICE : "<<knap_sack(n,mw)<<endl;

}

/*
5 20
2 3 4 5 9
3 4 5 8 10
*/

/*
4 5
2 3 4 5
3 4 5 6
*/

