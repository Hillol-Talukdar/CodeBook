#include<bits/stdc++.h>
using namespace std;

int countWays(int n)
{
    if (n <= 2)
        return -1;
    else
    {
        int ans = (n - 1) * (n - 2) / 2;
        return ans;
    }
}

int main()
{
    int n;
    cin>>n;
    cout<<countWays(n)<<endl;
}
