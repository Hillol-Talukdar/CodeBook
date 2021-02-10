#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void calculate_phi(ll n)
{
    ll phi[n+5],i,j;
    for(i=1;i<=n;i++)
        phi[i]=i;
    for(i=2;i<=n;i++)
    {
        if(phi[i] == i) // if i is prime
        {
            phi[i]= i-1; // Phi of a prime number i= i-1
            for(j=2*i;j<=n;j+=i)
               phi[j]-=(phi[j]/i) ; // phi[j] = (phi[j]/i) * (i-1);
        }
    }

    for(i=1;i<=n;i++)
        cout<<"phi("<<i<<") = "<<phi[i]<<endl;
}

int main()
{
    ll n,i;
    cin>>n;
    calculate_phi(n);
}
