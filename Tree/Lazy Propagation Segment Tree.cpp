#include<bits/stdc++.h>
using namespace std;

const int Max = 1e5 + 10;
int a[Max];
struct info
{
    int prop, seg;
}tree[Max*4];

void build(int node, int l, int r)
{
    tree[node].prop = 0;
    if(l==r)
    {
        tree[node].seg = a[l];
        return;
    }

    int mid= (l+r)>>1, lf= node<<1 ,rt= (node<<1)+1;

    build(lf, l, mid);
    build(rt, mid+1, r);

    tree[node].seg = tree[lf].seg + tree[rt].seg;
}

void update(int node, int l, int r, int L, int R, int val)
{
    if(L>r || R<l)
        return;
    if(l>=L && r<=R)
    {
        tree[node].seg += ((r-l+1) * val);
        tree[node].prop += val;
        return;
    }
    int mid= (l+r)>>1, lf= node<<1 ,rt= (node<<1)+1;

    update(lf, l, mid, L, R, val);
    update(rt, mid+1, r, L, R, val);

    tree[node].seg = tree[lf].seg + tree[rt].seg + (r-l+1) * tree[node].prop;
}

int query(int node, int l, int r, int L, int R, int carry=0)
{
    if(L>r || R<l)
        return 0;

    if(l>=L && r<=R)
        return tree[node].seg + carry * (r-l+1);

    int mid= (l+r)>>1, lf= node<<1 ,rt= (node<<1)+1;

    int u = query(lf, l, mid, L, R, carry + tree[node].prop);
    int v = query(rt, mid+1, r, L, R, carry + tree[node].prop);

    return u+v;
}

/*
int query(int node, int l, int r, int idx, int carry=0)
{
    if(idx<l || idx>r)
        return 0;
    if(l==r)
        return tree[node].seg + carry;

    int mid= (l+r)>>1, lf= node<<1 ,rt= (node<<1)+1;

    if(idx<=mid)
       return query(lf, l, mid, idx, carry + tree[node].prop);
    else
       return query(rt, mid+1, r, idx, carry + tree[node].prop);
}
*/
