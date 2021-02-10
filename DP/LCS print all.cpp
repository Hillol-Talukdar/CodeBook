#include<bits/stdc++.h>
using namespace std;

int dp[105][105],T,i,j;
string s,s1;

set<string> findLCS(int len, int l)
{
    set<string> st;
    if (!len || !l)
    {
        st.insert("");
        return st;
    }
    if(s[len-1]==s1[l-1])
    {
        set<string> tmp= findLCS( len-1, l-1);
        for (auto it : tmp)
            st.insert(it + s[len-1]);
    }
    else
    {
        if (dp[len-1][l] >= dp[len][l-1])
            st= findLCS( len-1 , l);
        if (dp[len][l-1] >= dp[len-1][l])
        {
            set<string> tmp= findLCS( len, l-1);
            st.insert(tmp.begin(), tmp.end());
        }
    }
    return st;
}

void LCS(int len, int l)
{
    for (i=0;i<=len;i++)
    {
        for (j=0;j<=l;j++)
        {
            if (!i || !j)
                dp[i][j]=0;
            else if (s[i-1] == s1[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max( dp[i-1][j] , dp[i][j-1]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin>>s>>s1;
    int len=s.size(),l=s1.size();
    LCS(len,l);
    set<string> st = findLCS( len, l);
    if(*st.cbegin()=="")
        cout<<"Not Found"<<endl;
    else
        for(auto it:st)
            cout<<it<<endl;
}


/*
AGTGATG
GTTAG
*/
