#include<bits/stdc++.h>
using namespace std;

int r,c;
bool visited[1005][1005];
string adj[1005];

void  dfs(int x, int y)
{
    if(x<0 || x>=r || y<0 || y>=c || visited[x][y])
        return;
    visited[x][y]=true;

    dfs(x-1,y);
    dfs(x,y-1);
    dfs(x,y+1);
    dfs(x+1,y);

//    dfs(x-1,y-1);
//    dfs(x-1,y);
//    dfs(x-1,y+1);
//    dfs(x,y-1);
//    dfs(x,y+1);
//    dfs(x+1,y-1);
//    dfs(x+1,y);
//    dfs(x+1,y+1);
}
