#include<bits/stdc++.h>
using namespace std;

int n,e,u,v,indegree[1000],i,node;
vector<int> adj[1000];

void topological_sort()
{
    vector<int> ans;
    list<int> indegree0;
    for(i=0;i<n;i++)
        if(!indegree[i])
            indegree0.push_back(i);
    while(!indegree0.empty())
    {
        u=indegree0.front();
        indegree0.pop_front();
        ans.push_back(u);
        int sz=adj[u].size();
        for(auto node:adj[u])
        {
            indegree[node]--;
            if(!indegree[node])
                indegree0.push_back(node);
        }
    }
    for(auto it:ans)
        cout<<it<<" ";
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
