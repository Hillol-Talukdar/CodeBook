#include<bits/stdc++.h>
using namespace std;

int u,v,src,tar,n,e,w,i,j,parent[10000],adj[1000][1000]={0},residual[1000][1000]={0};

bool bfs()
{
    bool visited[n+5]={false};
    queue<int> q;
    q.push(src);
    visited[src]=true;
    parent[src]=-1;
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        visited[u]=true;
        for(v=0;v<n;v++)
        {
            if(residual[u][v]>0 && visited[v]==false)
            {
                parent[v]=u;
                q.push(v);
                visited[v]=true;
            }
        }
    }
    if(visited[tar]==true)
        return true;
    return false;
}


void FordFulkerson()
{
    int max_flow=0;
    while(bfs()==true)
    {
        int path_flow=INT_MAX;
        for(v=tar; v!=src; v=parent[v])
        {
            u=parent[v];
          //  cout<<u<<endl;
            path_flow= min( path_flow, residual[u][v]);
        }
        for(v=tar; v!=src; v=parent[v])
        {
            u=parent[v];
            residual[u][v]-= path_flow;
            residual[v][u]+= path_flow;
        }
        max_flow+=path_flow;
    }
    cout<<"The Maximum Flow is : "<<max_flow<<endl;
}

int main()
{
   /* memset(adj,0,sizeof(adj[0][0])*1000*1000);
    memset(residual,0,sizeof(residual[0][0])*1000*1000);
    memset(parent,0,sizeof(parent));*/
    cin>>n>>e>>src>>tar;
    while(e--)
    {
        cin>>u>>v>>w;
        adj[u][v]=residual[u][v]=w;
      //  adj[v][u]=residual[v][u]=w;
    }
    FordFulkerson();
}

/*

6 10 0 5
0 1 16
0 2 13
1 2 10
1 3 12
2 1 4
2 4 14
3 2 9
3 5 20
4 3 7
4 5 4

*/


