#include<iostream>
#include<queue>
using namespace std;

const int Max = 1e4+5;
int n,v,i,u,mxedge,src,e;
bool adj[Max][Max]={false};

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

        for(v=0;v<n;v++)
            if(adj[u][v] && !visited[v])
                q.push(v) , visited[v]=true;
    }
    cout<<endl;
}

int main()
{
    cin>>n>>e>>src;
    while(e--)
    {
        cin>>u>>v;
        adj[u][v]=true;
        adj[v][u]=true;
    }
    bfs(src);
}


/*

/*

6 9
0 1
0 2
1 2
1 3
2 3
2 4
3 4
3 5
4 5
0

*/
