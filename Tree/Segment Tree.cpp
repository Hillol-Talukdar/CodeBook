#include<bits/stdc++.h>
using namespace std;

const int Max = 1e5 + 10;
int a[Max];
int seg[Max * 4];

void build(int node, int l, int r)
{
   /* if(l>r)
        return;*/
	if(l==r)
    {
		seg[node]=a[l];
		return;
	}
	int mid= (l+r)>>1, lf= node*2 ,rt= node*2+1;
	build(lf, l, mid);
	build(rt, mid+1, r);
	seg[node]=seg[lf]+seg[rt];
}

int update(int node, int l, int r, int idx, int val)
{
	if(l==r)
    {
		seg[node]=val;
		return seg[node];
	}
	int mid=(l + r)>>1, u=seg[node*2], v=seg[node*2+1];
	if(mid>=idx)
		u= update(2*node, l, mid, idx, val);
	else
		v = update(2*node+1, mid+1, r, idx, val);
	return seg[node]=u+v;
}

int query(int node, int l, int r, int L, int R)
{
	if(R<l || L>r)
		return 0;
	if(L<=l && r<=R)
		return seg[node];
	int mid = (l+r)>>1;
	int u = query(node*2, l, mid, L, R);
	int v = query(node*2+1, mid+1, r, L, R);
	return u+v;
}

int query(int node, int l, int r, int idx)
{
    if(l==r)
        return seg[node];
    int mid = (l+r)>>1;
    if(idx<=mid)
        return query(2*node,l,mid,idx);
    else
        return query(2*node+1,mid+1,r,idx);
}
