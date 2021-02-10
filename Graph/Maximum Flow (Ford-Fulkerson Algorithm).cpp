#include<bits/stdc++.h>
using namespace std;

int u,v,src,tar,n,e,w,i,j,parent[102],T,cs=1,residual[102][102];
vector< pair<int,int> > adj[102];

bool bfs()
{
    bool visited[n+5]={false};
    queue<int> q;
    q.push(src);
    visited[src]=true;
    parent[src]=-1;
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        visited[u]=true;
        int sz=adj[u].size();
        for(i=0;i<sz;i++)
        {
            int node=adj[u][i].first;
            if(residual[u][node]>0 && visited[node]==false)
            {
                parent[node]=u;
                q.push(node);
                visited[node]=true;
            }
        }
    }
    if(visited[tar]==true)
        return true;
    return false;
}

void FordFulkerson()
{
    int max_flow=0;
    while(bfs()==true)
    {
        int path_flow=INT_MAX;
        for(v=tar; v!=src; v=parent[v])
        {
            u=parent[v];
            path_flow= min( path_flow, residual[u][v]);
        }
        for(v=tar; v!=src; v=parent[v])
        {
            u=parent[v];
            residual[u][v]-= path_flow;
            residual[v][u]+= path_flow;
        }
        max_flow+=path_flow;
    }
    cout<<"Case "<<cs++<<": "<<max_flow<<endl;
}

int main()
{
    cin>>T;
    while(T--)
    {
        memset(residual,0,sizeof(residual[0][0])*102*102);
        memset(parent,0,sizeof(parent));
        for(i=0;i<102;i++)
            adj[i].clear();
        cin>>n>>src>>tar>>e;
        while(e--)
        {
            cin>>u>>v>>w;
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
            residual[u][v]=w;   //residual[u][v]+=w for multiple edge
            residual[v][u]=w;   //residual[v][u]+=w;
        }
        FordFulkerson();
    }
}

