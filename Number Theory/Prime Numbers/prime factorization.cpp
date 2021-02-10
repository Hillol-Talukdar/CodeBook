#include<bits/stdc++.h>
using namespace std;

void prime_factors(int n)
{
    int count=0,i;
    vector<int> vc;
    while(!(n%2))
    {
        vc.push_back(2);
        n/=2;
        count++;
    }
    for(i=3;i*i<=n;i+=2)
    {
        while(!(n%i))
        {
            vc.push_back(i);
            count++;
            n/=i;
        }
    }
    if(n>1)
    {
        vc.push_back(n);
        count++;
    }
    int sz=vc.size();
    cout<<"Number of Prime Factors : "<<count<<endl;
    for(i=0;i<sz;i++)
        cout<<vc[i]<<" ";
    cout<<endl;
}

int main()
{
    int n;
    cin>>n;
    prime_factors(n);
}
