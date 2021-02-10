#include<bits/stdc++.h>
using namespace std;

int n,i,j,k,e,c,src,u,v,w;
vector<pair<int,int> > adj[1000];

void bellman()
{
    bool p=false;
    int dist[1000];
    for(i=0;i<=n;i++)
        dist[i]=INT_MAX;
    dist[src]=0;
    for(c=0;c<n-1;c++)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<adj[i].size();j++)
            {
                u=i;
                v=adj[i][j].first;
                w=adj[i][j].second;
                if(dist[u]+w < dist[v])
                    dist[v]=dist[u]+w;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<adj[i].size();j++)
        {
            u=i;
            v=adj[i][j].first;
            w=adj[i][j].second;
            if(dist[u]+w < dist[v])
            {
                p=true;
                break;
            }
        }
    }
    if(p==true)
        cout<<"Negative cycle exits."<<endl;
    else
        for(i=0;i<n;i++)
            cout<<i<<"  "<<dist[i]<<endl;
}

int main()
{
    while(cin>>n>>e>>src)
    {
        for(i=0;i<n+5;i++)
            adj[i].clear();
        while(e--)
        {
            cin>>u>>v>>w;
            adj[u].push_back(make_pair(v,w));
        }
        bellman();
    }
}

/*
7 9 0
0 1 6
0 2 5
0 3 5
1 4 -1
2 1 -2
2 4 1
3 5 -1
4 6 3
5 6 3
*/

/*
7 9 0
0 1 6
0 2 5
0 3 5
1 4 -1
2 1 -2
4 2 1
3 5 -1
4 6 3
5 6 3
*/

