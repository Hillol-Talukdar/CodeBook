#include<bits/stdc++.h>
using namespace std;

int n,e,src,u,v,w,j;
vector<pair<int,int> > adj[1000];

void path(int parent[],int j)
{
    if(parent[j]==-1)
        return;
    path(parent,parent[j]);
    cout<<j<<" ";
}

int min_distance(int dist[],bool visited[])
{
    int mn=INT_MAX,min_index,i;
    for(i=0;i<n;i++)
        if(visited[i]==false && dist[i]<=mn)
        {
            mn=dist[i];
            min_index=i;
        }
    return min_index;
}

void dijkstra()
{
    int dist[n+1],i,parent[n+1];
    bool visited[n+1]={false};
    memset(parent,-1,sizeof(parent));
    for(i=0;i<n;i++)
        dist[i]=INT_MAX;
    dist[src]=0;
    for(i=0;i<n-1;i++)
    {
        u=min_distance(dist,visited);
        visited[u]=true;        // if visited[u]= true then dist[u] is the min distance from source.
        int sz=adj[u].size();
        for(j=0;j<sz;j++)
        {
            v=adj[u][j].first;
            w=adj[u][j].second;
            if(!visited[v] && ( dist[u]+w < dist[v] ) )
            {
                 dist[v]=dist[u]+w;
                 parent[v]=u;
            }

        }
    }
    for(i=0;i<n;i++)
    {
        cout<<i<<"  "<<dist[i]<<"     ";
        if(parent[i]==-1 && i!=src)
            cout<<"NO PATH";
        else
        {
            cout<<src<<" ";
            path(parent,i);
        }
        cout<<endl;
    }
}

int main()
{
    cin>>n>>e>>src;
    while(e--)
    {
        cin>>u>>v>>w;
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    dijkstra();
}

/*

9 14 0
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 5 4
2 8 2
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7

*/

