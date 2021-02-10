#include<bits/stdc++.h>
using namespace std;

int const Max = 1e5 + 10;
int par[Max],cnt[Max],rnk[Max],n;

int pos=0;
map<string,int> mp;

void make_set()
{
    for(int i = 0; i< n; i++)
    {
        par[i] = i;
        cnt[i] = 1;
        rnk[i] = 0;
    }
}

int find_rep(int x)
{
    if(x != par[x])
        par[x] = find_rep(par[x]);
    return par[x];
}

void union_(int u, int v)
{
    if((u = find_rep(u)) != (v = find_rep(v)))
    {
        if(rnk[u] <rnk[v])
        {
            cnt[v] += cnt[u];
            par[u] = par[v];
          //  return cnt[v];
        }
        else
        {
            rnk[u] = max(rnk[u], rnk[v] + 1);
            cnt[u] += cnt[v];
            par[v] = par[u];
        }
    }
   // return cnt[u];
}


void for_string_union(string s, string s2)
{
    if(!mp.count(s))
    {
        mp[s]=pos++;
        par[mp[s]]=mp[s];
    }
    if(!mp.count(s2))
    {
        mp[s2]=pos++;
        par[mp[s2]]=mp[s2];
    }

   // int u=find_rep(mp[s]), v=find_rep(mp[s2]);
}
