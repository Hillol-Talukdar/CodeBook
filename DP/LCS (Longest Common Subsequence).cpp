#include<bits/stdc++.h>
using namespace std;

int lcs(string s, string s2)
{
    int dp[100][100],len=s.size(),l2=s2.size(),i,j;
    for(i=0;i<=len;i++)
    {
        for(j=0;j<=l2;j++)
        {
            if(!i || !j)
                dp[i][j]=0;
            else if(s[i-1]==s2[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
        }
    }
   /* for(i=0;i<=len;i++)
    {
        for(j=0;j<=l2;j++)
           cout<<dp[i][j]<<" ";
        cout<<endl;
    }*/
    return dp[len][l2];
}

int main()
{
    string s,s2;
    cin>>s>>s2;

    cout<<"LCS : "<<lcs(s,s2)<<endl;
}

/*
abcbdab
bdcaba

*/
