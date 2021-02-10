#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,v,e,u1,u2,len,j;

    cin>>v>>e;  //max edge= v*(v-1)
    vector<int> al[e];
    for(i=1;i<=e;i++)
    {
        cin>>u1>>u2;
        if(u1>=v || u2>=v)
        {
            cout<<"Invalid"<<endl;
            i--;
        }
        else
        {
            al[u1].push_back(u2);
            al[u2].push_back(u1);
        }
    }
    for(i=0;i<v;i++)
    {
        len=al[i].size();
        sort(al[i].begin(),al[i].end());
        cout<<i<<" -> ";
        for(j=0;j<len;j++)
            cout<<al[i][j]<<" ";
        cout<<endl;
    }
}
