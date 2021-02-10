#include<bits/stdc++.h>
using namespace std;

/*
int calculate_phi(int n)
{
    int i,count=1;
    for(i=2;i<n;i++)
        if(__gcd(i,n)==1)
            count++;
    return count;
}
*/

int calculate_phi(int n)
{
    int  i,count=n;
    for(i=2;i*i<=n;i++)
    {
        if(!(n%i))
        {
            while(!(n%i))
                n/=i;
            count-=count/i;
        }
    }
    if(n>1)
        count-=count/n;
    return count;
}

int main()
{
    int n;
    cin>>n;
    cout<<"phi("<<n<<") = "<<calculate_phi(n)<<endl;
}
