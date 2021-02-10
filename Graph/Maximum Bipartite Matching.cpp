#include<bits/stdc++.h>
using namespace std;

int T,n,m,cs=1,i,j;
vector<int> adj[1005];

bool dfs(int u, bool visited[], int match[])
{
    int sz=adj[u].size();
    for (int i=0;i<sz;i++)
    {
        int v=adj[u][i];
        if(visited[v]==false)
        {
            visited[v]=true;
            if(match[v]<0 || dfs(match[v], visited, match))
            {
                match[v]=u;
                return true;
            }
        }
    }
    return false;
}

int bpm()
{
    int match[n],result=0;
    memset(match,-1,sizeof(match));
    for(int u=0;u<m;u++)
    {
        bool visited[n]={false};
        if(dfs(u, visited, match))
            result++;
    }
    return result;
}
