#include<bits/stdc++.h>
using namespace std;

int const Max = 1e5 + 10;
int u,e,v,n,dist[Max]={0},childs[Max]={0},par[Max];
bool visited[Max]={false};
vector<int> adj[Max];

int dfs(int u, int dis)
{
    visited[u]=true;
    dist[u]=dis;
    childs[u]=1;
    for(auto v:adj[u])
    {
        if(!visited[v])
        {
            par[v]=u;
            childs[u]+=dfs(v,dis+1);
        }
    }
    return childs[u];
}

int main()
{
    memset(par,-1,sizeof(par));

    cin>>n>>e;
    while(e--)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0,0);
}
