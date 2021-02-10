#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[100][100]={false},n,i,j,v,e1,e2;
    cin>>v;
    for(i=1;i<=v;i++)
    {
        cin>>e1>>e2;
        a[e1][e2]=true;
        a[e2][e1]=true;
    }
    for(i=0;i<=v;i++)
    {
        for(j=0;j<=v;j++)
        {
            if(i==0 && j==0)
                cout<<"   ";
            else if(j==0)
                cout<<"V"<<i<<" ";
            else if(i==0)
                cout<<"E"<<j<<" ";
            else
             cout<<a[i][j]<<"  ";
        }

        cout<<endl;
    }
}
/*
5
1 2
2 3
4 5
2 1
4 5
*/
