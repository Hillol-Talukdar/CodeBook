#include<bits/stdc++.h>
using namespace std;

int n,adj[100][100],big=50000,e,u,v,w,i,j,k;

void fw()
{
    for(k=0;k<n;k++)
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
               // if( adj[i][k]+adj[k][j] < adj[i][j])
                    adj[i][j]=min( adj[i][k]+adj[k][j] , adj[i][j]);
}

int main()
{
    while(cin>>n>>e)
    {
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                (i==j) ? adj[i][j]=0 : adj[i][j]=big;
        while(e--)
        {
            cin>>u>>v>>w;
            adj[u-1][v-1]=w;
        }
        fw();
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(adj[i][j]==big)
                    cout<<"N ";
                else
                    cout<<adj[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}

/*

4 6
1 2 3
2 1 8
1 4 7
4 1 2
2 3 2
3 4 1

*/
