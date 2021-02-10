#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
    string a,b;
    cin>>a>>b;
    int m[100][100],len=a.size(),l=b.size(),i,j;
    for(i=0;i<=len;i++)
    {
        for(j=0;j<=l;j++)
        {
            if(!i)
                m[i][j]=j;
            else if(!j)
                m[i][j]=i;
            else if(a[i-1]==b[j-1])
                m[i][j]=m[i-1][j-1];
            else
                m[i][j]=min( min( m[i-1][j-1], m[i-1][j] ) , m[i][j-1] ) +1;
        }
    }
   /* for(i=0;i<=len;i++)
    {
        for(j=0;j<=l;j++)
           cout<<m[i][j]<<" ";
        cout<<endl;
    }*/
    cout<<"ED : "<<m[len][l]<<endl;
}

/*
gambol
gumbo

*/
