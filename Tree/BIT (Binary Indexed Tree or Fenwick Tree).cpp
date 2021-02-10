#include <bits/stdc++.h>
using namespace std;

const int Max = 1e5 + 10;

int n,a[Max],BIT[Max];

void update(int idx, int val)
{
	while(idx <= n)
    {
		BIT[idx] += val;
		idx += idx & -idx;
	}
}

void build()
{
    memset(BIT,0,sizeof(BIT));
	for(int i=1;i<=n;i++)
		update(i, a[i]);
}

int query(int idx)
{
	int ret = 0;
	while(idx > 0)
    {
		ret += BIT[idx];
		idx -= idx & -idx;
	}
	return ret;
}

int query(int l, int r)
{
	return query(r) - query(l-1);
}

int main()
{
	int q,l,r;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);

	build();
	while(q--)
    {
		scanf("%d%d",&l,&r);
		printf("%d\n", query(l, r));
	}
}
