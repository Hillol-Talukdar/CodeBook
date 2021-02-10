#include<bits/stdc++.h>
using namespace std;

int inf = 1e6;

void coin_combination(int a[] , int par[] , int total)
{
    if(par[total]==-1)
    {
        cout<<"Not possible"<<endl;
        return;
    }
    int start=total;
    cout<<"Coins used to form total : ";

    while(start>0)
    {
        int i = par[start];
        cout<<a[i]<<" ";
        start= start- a[i];
    }
    cout<<endl;
}

int coin_change(int a[], int n, int total)
{
    int dp[total+5],i,j,par[total+5];
    dp[0]=0;
    for(i=1;i<=total;i++)
        dp[i]=inf , par[i]=-1;

    for(i=0;i<n;i++)
    {
      //  for(j=total;j>0;j--)
        for(j=1;j<=total;j++)
        {
            if(j >= a[i] && (dp[j-a[i]] +1) < dp[j])
            {
                dp[j] = 1 + dp[j-a[i]];
                par[j]= i;
            }
        }
    }

    coin_combination(a, par , total);

    return dp[total];
}

int main()
{
    int a[1005],n,total,i;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    cin>>total;

    cout<<"Minimum number of coins needed : "<<coin_change(a,n,total)<<endl;;
}

