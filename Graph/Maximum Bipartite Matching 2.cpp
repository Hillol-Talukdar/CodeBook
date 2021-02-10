#include<bits/stdc++.h>
using namespace std;

int T,n,m,cs=1,i,j;
bool adj[105][105];

bool dfs(int u, bool visited[], int match[])
{
    for(int v=0; v<n; v++)
    {
        if(adj[u][v] && visited[v]==false)
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
