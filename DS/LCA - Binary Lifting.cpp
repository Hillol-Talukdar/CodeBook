#include <bits/stdc++.h>
using namespace std;

const int Max = 1e4 + 5;

int sparse[Max][22],depth[Max],lg,dist[Max];
vector<int> adj[Max];
//vector<pair<int,int> > adj[Max];


void dfs(int from, int u, int dep)
{
    depth[u] = dep;
    sparse[u][0] = from;

    for(int i=1;i<=lg;i++)
    {
        sparse[u][i] = sparse[sparse[u][i-1]][i-1];
        if(sparse[u][i] == -1)
            break;
    }

    for(auto it : adj[u])
    {
        int v = it;
//        int v = it.FI , w = it.SE;
        if(v==from)
            continue;
//        dist[v] = dist[u] + w;
        dfs(u, v, dep+1);
    }
}

int lca_query(int u, int v) {
    if(depth[u] < depth[v])
        swap(u, v);
    int diff = depth[u] - depth[v];

    for(int i=0; i<lg; i++)
    {
        if((1<<i) & diff)
            u = sparse[u][i];
    }

    if(u == v)
        return u;

    for(int i=lg-1; i>=0; i--)
        if(sparse[u][i] != sparse[v][i])
            u = sparse[u][i] , v = sparse[v][i];

    return sparse[u][0];
}

int kthancestor(int u, int k)
{
    int lg;
    for(lg=1; 1<<lg <= depth[u];lg++);
    lg--;

    for(int i=lg;i>=0;i--)
    {
        if(depth[u] - (1<<i) >= k )
            u = sparse[u][i];
    }
    return u;
}

int kthancestor(int u, int v, int k) // kthancestor from node u to v
{
    int lca = lca_query(u,v), node;
    if(depth[u]-depth[lca]+1 >= k)
        node = kthancestor(u , depth[u]-k+1);
    else
        node = kthancestor(v, 2*depth[lca]+k - depth[u]-1);
    return node;
}

void init()
{
    memset(depth,0,sizeof(depth));
    memset(dist,0,sizeof(dist));
    memset(sparse,-1,sizeof(sparse));
    for(int i=0;i<Max;i++)
        adj[i].clear();
}

int main()
{
    int n,u,v,q,e;
    scanf("%d",&n);
    lg = log2(n);
    e=n-1;
    for(int i=0;i<e;i++)
    {
        scanf("%d%d",&u,&v);
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    dfs(0, 0, 0);

    scanf("%d",&q);
    while(q--)
    {
        scanf("%d%d",&u,&v);
        printf("%d\n",lca_query(u, v));
    }
}
