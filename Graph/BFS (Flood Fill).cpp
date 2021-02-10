#include<bits/stdc++.h>
using namespace std;

int n,r,c,dist[105][105];
string adj[1005];
int X[4]={-1,0,0,1},Y[4]={0,-1,1,0};
//int X[8]={-1,-1,-1,0,0,1,1,1},Y[8]={-1,0,1,-1,1,-1,0,1};


void bfs(int x, int y)
{
//    for(int i=0;i<105;i++)
//        for(int j=0;j<105;j++)
//            dist[i][j]=INT_MAX;

    int ux,uy,vx,vy;
    bool visited[105][105]={false};
    queue<pair<int,int> > q;

    dist[x][y]=0;
    visited[x][y]=true;
    q.push({x,y});

    while(!q.empty())
    {
        ux = q.front().first;
        uy = q.front().second;
        q.pop();

        for(int i=0;i<4;i++)
        {
            vx = ux+X[i];
            vy = uy+Y[i];
            if((vx>=0 && vx<r) && (vy>=0 && vy<c) && !visited[vx][vy])
            {
                visited[vx][vy]=true;
//                dist[vx][vy] = min( dist[ux][uy]+1 , dist[vx][vy]);
                q.push({vx,vy});
            }
        }
    }
}
