#include "bits/stdc++.h"
using namespace std;

vector<int> spf; //smallest prime factor for every number


void sieve(int n)
{
    spf[1] = 1;
    for(int i=2; i<n; i++)
        spf[i] = i;
    for(int i=4; i<n; i+=2)
        spf[i] = 2;
    for(int i=3; i*i<=n; i+=2)
        if (spf[i] == i)
            for (int j=i*i; j<n; j+=i)
                if (spf[j]==j)
                    spf[j] = i;
}

vector<int> prime_factors(int x)
{
    vector<int> vc;
    while (x != 1)
    {
        vc.push_back(spf[x]);
        x = x / spf[x];
    }
    return vc;
}

int main()
{
    sieve(10000);
    int x;
    cin>>x;
    cout << "prime factorization for " << x << " : ";
    vector <int> p = prime_factors(x);

    for (int i=0; i<p.size(); i++)
        cout << p[i] << " ";
    cout << endl;
}

