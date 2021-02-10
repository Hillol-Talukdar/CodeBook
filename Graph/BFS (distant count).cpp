#include<bits/stdc++.h>
using namespace std;

const int Max = 1e4+5;
int src,u,s,e,v,tar,node,i,n;
vector<int> adj[Max];


void bfs()
{
    int dist[Max]={0};
    bool visited[Max]={false};
    queue<int> q;

    q.push(src);
    visited[src]=true;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(auto v:adj[u])
        {
            if(!visited[v])
            {
                visited[v]=true;
                dist[v]=dist[u]+1;
                q.push(v);
            }
        }
    }
    cout<<dist[tar]<<endl;
}

int main()
{
    cin>>n>>e;
    while(e--)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin>>src>>tar;
    bfs();
  //  cout<<dist[tar]<<endl;
}
