#include<bits/stdc++.h>
using namespace std;

const int Max = 3e4+5;

vector<int>adj[Max];
int a[Max];

///  For HLD Function
int chainNo, ptr, chainHead[Max], chainPos[Max], chainIdx[Max] , sub[Max] , maxSub[Max];

/// For Segment Tree and BIT
int arr[Max], tree[4*Max];

/// For LCA
int dep[Max], parent[Max], sparse[Max][20];

void init(const int& n)
{
    for(int i=0; i<=n; i++)
        adj[i].clear();
    chainNo = 0;
    ptr = 0;
    memset(chainHead,-1,sizeof chainHead);
    memset(tree,0,sizeof tree);
    memset(parent,-1,sizeof parent);
}

/// BIT Part
void BIT_Update(int idx,const int& x,const int& n)
{
    while(idx <= n)
    {
        tree[idx] += x;
        idx += idx & (-idx);
    }
}

int BIT_Query(int idx,const int& n)
{
    int sum = 0;
    while(idx > 0)
    {
        sum += tree[idx];
        idx -= idx & (-idx);
    }
    return sum;
}

int BIT_Query(int l,int r,const int& n)
{
    return BIT_Query(r,n) - BIT_Query(l-1,n);
}

/// Segment Tree Part
void seg_Build(int pos,int l,int r)
{
    if(l == r)
    {
        tree[pos] = arr[l];
        return;
    }

    int mid = (l+r)>>1, lt = pos<<1, rt = (pos<<1)+1;

    seg_Build(lt,l,mid);
    seg_Build(rt,mid+1,r);

    tree[pos] = tree[lt]+tree[rt];
}

void seg_Update(int pos,int l,int r,int idx,int val)
{
    if(l == r)
    {
        tree[pos] = val;
        return;
    }

    int mid = (l+r)>>1, lt = pos<<1, rt = (pos<<1)+1;

    if(idx <= mid)
        seg_Update(lt,l,mid,idx,val);
    else
        seg_Update(rt,mid+1,r,idx,val);

    tree[pos] = tree[lt]+tree[rt];
}

int seg_Query(int pos,int l,int r,int L,int R)
{
    if(l > R || r < L)
        return 0;
    else if(l >= L && r <= R)
        return tree[pos];

    int mid = (l+r)>>1, lt = pos<<1, rt = (pos<<1)+1;

    int x = seg_Query(lt,l,mid,L,R);
    int y = seg_Query(rt,mid+1,r,L,R);

    return x+y;
}

/// LCA Part
void DFS(int src,int par,int lev)
{
    dep[src] = lev;
    parent[src] = par;
    sub[src] = 1 , maxSub[src] = -1;
    int mx = 0;

    for(auto it : adj[src])
    {
        int x = it;

        if(x == par)
            continue;

        DFS(x,src,lev+1);
        sub[src] += sub[x];

        if(sub[x] > mx)
            mx = sub[x] , maxSub[src] = x;
    }
}

void initLCA(const int& n)
{
    memset(sparse,-1,sizeof sparse);

    for(int i=1; i<=n; i++)
        sparse[i][0] = parent[i];

    for(int j=1; 1<<j <n; j++)
        for(int i=1; i<=n; i++)
            if(sparse[i][j-1] != -1)
                sparse[i][j] = sparse[sparse[i][j-1]][j-1];
}

int LCA_query(int u,int v)
{
    if(dep[u] < dep[v])
        swap(u,v);

    int log = log2(dep[u]);

    for(int i=log; i>=0; i--)
    {
        if(dep[u]-(1<<i) >= dep[v])
            u = sparse[u][i];
    }

    if(u == v)
        return u;

    for(int i=log; i>=0; i--)
        if(sparse[u][i] != -1 && sparse[u][i] != sparse[v][i])
            u = sparse[u][i] , v = sparse[v][i];

    return parent[u];
}

/// HLD Part
void HLD(int cur,int par)
{
    if(chainHead[chainNo] == -1)
        chainHead[chainNo] = cur;

    chainIdx[cur] = chainNo;
    chainPos[cur] = ++ptr;
    arr[ptr] = a[cur];

    if(maxSub[cur] != -1)
        HLD(maxSub[cur], cur);

    for(auto it : adj[cur])
    {
        int i = it;
        if(i != par && i != maxSub[cur])
            chainNo++, HLD(i, cur);
    }
}

int query_up(int u,int v,const int& n)
{
    int uchain , vchain = chainIdx[v] , ans = 0;

    while(chainIdx[u] != vchain)
    {
        uchain = chainIdx[u];

        ans += BIT_Query(chainPos[chainHead[uchain]], chainPos[u], n);

        u = chainHead[uchain];
        u = sparse[u][0];
    }
    ans += BIT_Query(chainPos[v], chainPos[u], n);

    return ans;
}

void ansUpdate(int idx,int val,const int& n)
{
    BIT_Update(chainPos[idx],val-a[idx],n);
    a[idx] = val;
}

int ansQuery(const int& n,int u,int v)
{
    int lca = LCA_query(u,v);

    int q1 = query_up(u,lca,n);
    int q2 = query_up(v,lca,n);

    return q1+q2-a[lca];
}

int main()
{
    int T,n,q,u,v,type,cs=1;

    scanf("%d",&T);

    while(T--)
    {
        scanf("%d",&n);

        init(n+5);

        for(int i=1; i<=n; i++)
            scanf("%d",&a[i]);

        for(int i=1; i<n; i++)
        {
            scanf("%d%d",&u,&v);

            adj[++u].emplace_back(++v);
            adj[v].emplace_back(u);
        }

        DFS(1,-1,0);
        initLCA(n);
        HLD(1,-1);

        for(int i=1;i<=ptr;i++)
            BIT_Update(i,arr[i],n);;

        scanf("%d",&q);
        printf("Case %d:\n",cs++);

        while(q--)
        {
            scanf("%d%d%d",&type,&u,&v);

            if(type)
                ansUpdate(u+1,v,n);
            else
                printf("%d\n",ansQuery(n,u+1,v+1));
        }
    }
}
