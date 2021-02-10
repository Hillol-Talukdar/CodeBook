#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void countConsecutive(ll n)
{
    ll st=1,en=(n+1)/2,i,j;
    while(st<en)
    {
        ll sum=0;
        for(i=st;i<=en;i++)
        {
            sum+=i;
            if(sum==n)
            {
                for(j=st;j<=i;j++)
                    cout<<j<<" ";
                cout<<endl;
                break;
            }
            else if(sum>n)
                break;
        }
        st++;
    }
}

int main()
{
    ll n;
    cin>>n;
    countConsecutive(n);
}

