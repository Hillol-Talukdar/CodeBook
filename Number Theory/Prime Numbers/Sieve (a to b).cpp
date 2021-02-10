#include<bits/stdc++.h>
using namespace std;

vector<long> prime;

void sieve(long n,long m)
{
    long  i,j,x=0;
    bool notprime[m+1]={false};
    if(n<=2 && m>=2)
        prime.push_back(2);
    for(i=3;i*i<=m;i+=2)
        if(notprime[i]==false)
            for(j=i*i;j<=m;j+=i)
                notprime[j]=true;
    for(i=3;i<=m;i+=2)
    {
        if(notprime[i]==false)
            if(i>=n)
                prime.push_back(i);
    }
    if(!prime.size())
        cout<<"No Number";
    else
        for(i=0;i<prime.size();i++)
            cout<<prime[i]<<" ";
    cout<<endl;
}

int main()
{
    long n,m;
    while(scanf("%ld%ld",&n,&m)!=EOF)
        sieve(n,m);
    return 0;
}
