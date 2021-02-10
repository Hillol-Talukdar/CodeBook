#include<bits/stdc++.h>
using namespace std;

const int Max = 1e3+5;
int n,e,u,v,src,i;
vector<int> adj[Max];
bool visited[Max]={false};
/*
void dfs(int u)
{
    if(!visited[u])
        cout<<u<<" ";
    visited[u]=true;
    for(auto v:adj[u])
        if(!visited[v])
            dfs(v);
}
*/

void dfs(int src)
{
    bool visited[Max]={false};
    stack<int> st;

    st.push(src);
    visited[src]=true;
    while(!st.empty())
    {
        int u=st.top();
        st.pop();

        cout<<u<<" ";

        for(auto v:adj[u])
            if(!visited[v])
                st.push(v) , visited[v]=true;
    }
    cout<<endl;
}


int main()
{
    while(cin>>n>>e>>src)
    {
        memset(visited,false,sizeof(visited));
        for(i=0;i<n;i++)
            adj[i].clear();
        while(e--)
        {
          cin>>u>>v;
          adj[u].push_back(v);
          adj[v].push_back(u);
        }
        dfs(src);
        cout<<endl;
    }
}

/*
5 7 0
0 1
1 2
0 2
3 0
2 3
2 4
4 3
*/
