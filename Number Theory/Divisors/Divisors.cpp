#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,n;
    cin>>n;
    for(i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            if(i==n/i)
                cout<<i<<" ";
            else
                cout<<i<<" "<<n/i<<" ";
        }
    }
    cout<<endl;
}
