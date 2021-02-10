#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,n,count=0,sum=0;
    cin>>n;
    for(i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            if(i==n/i)
            {
                count++;
                sum+=i;
            }
            else
            {
                count+=2;
                sum+=i+n/i;
            }
        }
    }
    cout<<sum<<" "<<count<<endl;
    return 0;
}
