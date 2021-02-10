#include<bits/stdc++.h>
using namespace std;

//for finding distinct

typedef long long ll;
typedef unsigned long long ull;

#define N 311111
#define BLOCK_SIZE 555
int a[N],freq[N],ans[N],q,n,sum;

struct node
{
    int L,R,indx;
}query[N];

bool cmp(node x, node y)
{
    if(x.L/BLOCK_SIZE != y.L/BLOCK_SIZE)
        return x.L/BLOCK_SIZE < y.L/BLOCK_SIZE;
    return x.R < y.R;
}

void add(int pos)
{
    freq[pos]++;
    if(freq[pos]==1)
        sum++;
}

void del(int pos)
{
    freq[pos]--;
    if(freq[pos]==0)
        sum--;
}

void MOs()
{
   // BLOCK_SIZE= sqrt(n);
    sort(query,query+q,cmp);
    int st=0,en=-1,i;
    for(i=0;i<q;i++)
    {
        int l= query[i].L , r= query[i].R;
        while(st>l)
            add(a[--st]);
        while(st<l)
            del(a[st++]);
        while(en<r)
            add(a[++en]);
        while(en>r)
            del(a[en--]);

        ans[query[i].indx] = sum;
    }
}

int main()
{
    int i,l,r;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    scanf("%d",&q);
    for(i=0;i<q;i++)
    {
        scanf("%d%d",&query[i].L,&query[i].R);
        query[i].indx=i;
    }

    MOs();

    for(i=0;i<q;i++)
        printf("%d\n",ans[i]);
}
