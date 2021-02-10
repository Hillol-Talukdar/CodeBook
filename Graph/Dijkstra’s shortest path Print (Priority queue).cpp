#include<bits/stdc++.h>
using namespace std;

int n,e,u,v,i,src,w;
vector<pair<int,int> > adj[1000];

void path(int parent[],int j)
{
    if(parent[j]==-1)
        return;
    path(parent,parent[j]);
    cout<<j<<" ";
}

void dijkstra()
{
    priority_queue<pair<int,int> ,vector<pair<int,int> >, greater<pair<int,int> > > pq;
    bool visited[n+1]={false};
    int dist[n+1],parent[n+1];
    memset(parent,-1,sizeof(parent));
    for(i=0;i<n;i++)
        dist[i]=INT_MAX;
    dist[src]=0;
    pq.push(make_pair(0,src));
    while(!pq.empty())
    {
        u=pq.top().second;
        pq.pop();
        if(visited[u])
            continue;
        visited[u]=true;
        int sz= adj[u].size();
        for(i=0;i<sz;i++)
        {
            v=adj[u][i].first;
            w=adj[u][i].second;
            if(!visited[v] && ( dist[u]+w < dist[v] ) )
            {
                dist[v]=dist[u]+w;
                pq.push(make_pair(dist[v],v));
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
