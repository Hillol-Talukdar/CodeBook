#include<iostream>
#include<stack>
using namespace std;

const int Max= 1e4 +5;
int visited[Max]={false},adj[Max][Max],n,u,v,e,src;
stack<int> st;


void dfs(int src)
{
    st.push(src);
    while(!st.empty())
    {
        u=st.top();
        st.pop();
        if(!visited[u])
        {
            cout<<u<<" ";
            visited[u]=true;
        }
        for(int v=0;v<n;v++)
        {
            if(adj[u][v]==true && !visited[v])
                st.push(v);
        }
    }
    cout<<endl;
}
int main()
{
    cin>>n>>e;
    while(e--)
    {
        cin>>u>>v;
        adj[u][v]=true;
        adj[v][u]=true; //for undirected graph
    }
    cin>>src;
    dfs(src);
}

/*
5
1 0
0 2
2 1
0 3
1 4
*/
