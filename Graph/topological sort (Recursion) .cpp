#include<bits/stdc++.h>
using namespace std;

int n,e,u,v,indegree[1000],i,node;
vector<int> adj[1000];
stack<int> st;

void dfs(bool visited[],int u)
{
    visited[u]=true;
    for(auto v:adj[u])
        if(visited[v]==false)
            dfs(visited,v);
    st.push(u);
}

void topological_sort()
{
    bool visited[n+5]={false};
    for(i=0;i<n;i++)
        if(visited[i]==false)
            dfs(visited,i);
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
}

int main()
{
    memset(indegree,0,sizeof(indegree));
    cin>>n>>e;
    while(e--)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        indegree[v]++;
    }
    topological_sort();
}

/*

6 6
5 2
5 0
4 0
4 1
2 3
3 1

*/
