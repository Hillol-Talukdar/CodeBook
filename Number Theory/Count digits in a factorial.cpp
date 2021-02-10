#include<bits/stdc++.h>
using namespace std;

int digits[10000005],x;

void find_digits(int n)
{
    double dgts=0.0;
    for(int i=1;i<=n;i++)
    {
        dgts+=log10(i);
        digits[i]=(int) dgts+1;
    }
}

int main()
{
    find_digits(10000000);
    cin>>x;
    if(x<=0)
        cout<<0<<endl;
    else
        cout<<digits[x]<<endl;
}
