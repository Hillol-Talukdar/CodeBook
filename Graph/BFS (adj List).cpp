#include<bits/stdc++.h>
using namespace std;

const int Max = 1e4+5;
int src,u,e,v,n;
vector<int> adj[Max];


void bfs(int src)
{
    bool visited[Max]={false};
    queue<int> q;

    q.push(src);
    visited[src]=true;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();

        cout<<u<<" ";

        for(auto v:adj[u])
            if(!visited[v])
                q.push(v) , visited[v]=true;
    }
    cout<<endl;
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
    cin>>src;
    bfs(src);
}

/*
5 5
1 0
0 2
2 1
0 3
1 4
0
*/
