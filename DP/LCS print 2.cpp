#include<bits/stdc++.h>
using namespace std;

string s,s1;

void lcs(int len, int l)
{
    int dp[len+1][l+1];
    for(int i=0;i<=len;i++)
    {
        for(int j=0;j<=l;j++)
        {
            if (!i || !j)
                dp[i][j] = 0;
            else if(s[i-1] == s1[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max( dp[i-1][j], dp[i][j-1]);
        }
    }
    int i=len,j=l;
    string ans;
    while(i>0 && j>0)
    {
        if(s[i-1] == s1[j-1])
        {
            ans+=s[i-1];
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1])
            i--;
        else
            j--;
    }
    reverse(ans.begin(),ans.end());
    cout << "LCS of " <<s<<" and "<<s1<<" is: "<<ans<<endl;
}

int main()
{
    cin>>s>>s1;
    int len=s.size(),l=s1.size();
    lcs(len , l);
}

/*
abcbdab
bdcaba

*/
