#include<bits/stdc++.h>
using namespace std;

const int Max = 1e5 + 10;
int a[Max];
int seg[Max<<2],lazy[Max<<2];

void build(int node, int l, int r)
{
    lazy[node]=0;
	if(l==r)
    {
		seg[node]=a[l];
		return;
	}
	int mid= (l+r)>>1, lf= node<<1 ,rt= (node<<1)+1;
	build(lf, l, mid);
	build(rt, mid+1, r);
	seg[node] = seg[lf] + seg[rt];
}

void propagate(int node, int l, int r)
{
    if(lazy[node]) //if !lazy[node] then its up to dated
    {
        int mid= (l+r)>>1, lf= node<<1 ,rt= (node<<1)+1;
        seg[node] += ((r-l+1) * lazy[node]);
        if(l!=r)    // l==r then it is leap node
        {
            lazy[lf] += lazy[node];
            lazy[rt] += lazy[node];
        }
        lazy[node]=0;
    }
}

void update(int node, int l, int r, int L, int R, int val)
{
    propagate(node, l, r);

    if(l>R || r<L)   //Out of range
        return;
    int mid= (l+r)>>1, lf= node<<1 ,rt= (node<<1)+1;

    if(l>=L && r<=R)    //Fully Overlap
    {
        seg[node] += ((r-l+1) * val);
        if(l!=r)
        {
            lazy[lf] += lazy[node];
            lazy[rt] += lazy[node];
        }
        return;
    }

    update(lf, l, mid, L, R, val);
    update(rt, mid+1, r, L, R, val);

    seg[node]=seg[node*2]+ seg[node*2+1];
}

int query(int node, int l, int r, int L, int R)
{
    if(R<l || L>r)
		return 0;

    propagate(node, l, r);

	if(L<=l && r<=R)
		return seg[node];
	int mid= (l+r)>>1, lf= node<<1 ,rt= (node<<1)+1;
	int u = query(lf, l, mid, L, R);
	int v = query(rt, mid+1, r, L, R);
	return u+v;
}

