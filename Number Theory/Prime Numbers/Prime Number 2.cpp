#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int flag=true;
    cin>>n;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            cout<<n<<" is not prime"<<endl;
            flag=true;
            return 0;
        }
    }
    if(flag)
        cout<<n<<" is prime"<<endl;
}
