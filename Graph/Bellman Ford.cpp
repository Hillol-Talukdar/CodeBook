#include<bits/stdc++.h>
using namespace std;

int n,i,j,k,e,c,src,u,v,w,tar;
vector<pair<int,int> > adj[1000];

int bellman()
{
    int dist[1000],parent[1000];
    memset(parent,-1,sizeof(parent));
    for(i=1;i<=n+5;i++)
        dist[i]=INT_MAX;
    dist[src]=0;
    for(c=0;c<n-1;c++)
    {
        for(i=1;i<=n;i++)
        {
            for(j=0;j<adj[i].size();j++)
            {
                u=i;
                v=adj[i][j].first;
                w=adj[i][j].second;
                if(dist[u]+w < dist[v])
                {
                    dist[v]=dist[u]+w;
                    parent[v]=u;
                }
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=0;j<adj[i].size();j++)
        {
            u=i;
            v=adj[i][j].first;
            w=adj[i][j].second;
            if(dist[u]+w < dist[v])
                return -1;
        }
    }
    return dist[tar];
}

int main()
{
    while(cin>>n>>e>>src>>tar)
    {
        for(i=0;i<n+5;i++)
            adj[i].clear();
        while(e--)
        {
            cin>>u>>v>>w;
            adj[u].push_back(make_pair(v,w));
        }
        int ans=bellman();
        cout<<endl;
        if(ans==-1)
            cout<<"Negative cycle exits."<<endl;
        else
            cout<<src<<" "<<tar<<" "<<ans<<endl;
    }
}

/*
7 9 1 7
1 2 6
1 3 5
1 4 5
2 5 -1
3 2 -2
5 3 1
4 6 -1
5 7 3
6 7 3
*/


/*
7 9 1 7
1 2 6
1 3 5
1 4 5
2 5 -1
3 2 -2
3 5 1
4 6 -1
5 7 3
6 7 3
*/
