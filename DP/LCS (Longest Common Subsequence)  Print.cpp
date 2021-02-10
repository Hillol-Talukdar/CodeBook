#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

string a,b,ans;
int m[100][100],len,l2,i,j;
char track[100][100];

void print()
{
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
}

void lcs()
{
    while(len>0 && l2>0)
    {
        if(track[len][l2]=='d')
        {
           ans+=a[len-1];
           len--;
           l2--;
        }
        else if(track[len][l2]=='u')
            len--;
        else if(track[len][l2]=='l')
            l2--;
    }
    print();
}

int main()
{

    cin>>a>>b;
    len=a.size();
    l2=b.size();
    for(i=0;i<=len;i++)
    {
        for(j=0;j<=l2;j++)
        {
            if(!i || !j)
                m[i][j]=0;
            else if(a[i-1]==b[j-1])
            {
                m[i][j]=m[i-1][j-1]+1;
                track[i][j]='d';
            }
            else
            {
                if(m[i-1][j]>= m[i][j-1])
                    track[i][j]='u';
                else if(m[i-1][j]<m[i][j-1])
                    track[i][j]='l';
                m[i][j]=max(m[i-1][j], m[i][j-1]);
            }
        }
    }
    lcs();
}

/*
abcbdab
bdcaba

*/

