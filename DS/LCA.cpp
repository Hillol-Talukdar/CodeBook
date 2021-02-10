#include <bits/stdc++.h>
using namespace std;

const int Max = 1e4 + 5;

int sparse[Max][22],depth[Max],par[Max],dist[Max];
vector<int> adj[Max];
//vector<pair<int,int> > adj[Max];

void dfs(int from, int u, int dep)
{
    par[u] = from;
    depth[u] = dep;
    for(auto it : adj[u])
    {
        int v = it;
//        int v = it.FI , w = it.SE;
        if(v == from)
            continue;
//        dist[v] = dist[u] + w;
        dfs(u, v, dep+1);
    }
}

void lca_init(int n)
{
    memset(sparse, -1, sizeof(sparse));
    for(int i=0;i<n;i++)
        sparse[i][0] = par[i];

    for(int j=1; 1<<j < n;j++)
        for(int i=0;i<n;i++)
            if(sparse[i][j-1] != -1)
                sparse[i][j] = sparse[ sparse[i][j-1] ][j-1];
}

int query(int u, int v)
{
    int lg=1;
    if(depth[u] < depth[v])
        swap(u, v);

    while(1)
    {
        int nxt = lg+1;
        if( (1<<nxt) > depth[u])
            break;
        lg++;
    }

    for(int i=lg;i>=0;i--)
    {
        if(depth[u] - (1<<i) >= depth[v])
            u = sparse[u][i];
    }

    if(u == v)
        return u;

    for(int i=lg;i>=0;i--)
        if( (sparse[u][i] != -1) && (sparse[u][i] != sparse[v][i]) )
            u = sparse[u][i], v = sparse[v][i];

    return par[u];
}

int kthancestor(int u, int k)
{
    int lg;
    for(lg=1; 1<<lg <= depth[u];lg++);
    lg--;

    for(int i=lg;i>=0;i--)
        if(depth[u] - (1<<i) >= k )
            u = sparse[u][i];

    return u;
}

int kthancestor(int u, int v, int k) // kthancestor from node u to v
{
    int lca = query(u,v), node;
    if(depth[u]-depth[lca]+1 >= k)
        node = kthancestor(u , depth[u]-k+1);
    else
        node = kthancestor(v, 2*depth[lca]+k - depth[u]-1);
    return node;
}

void init()
{
    memset(par,0,sizeof(par));
    memset(depth,0,sizeof(depth));
    memset(dist,0,sizeof(dist));
    for(int i=0;i<Max;i++)
        adj[i].clear();
}

int main()
{
    int n,u,v,q,e;
    scanf("%d",&n);
    e=n-1;
    for(int i=0;i<e;i++)
    {
        scanf("%d%d",&u,&v);
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    dfs(0, 0, 0);
    lca_init(n);

    scanf("%d",&q);
    while(q--)
    {
        scanf("%d%d",&u,&v);
        printf("%d\n",query(u, v));
    }
}

//Complexity: O(NlgN,lgN)
