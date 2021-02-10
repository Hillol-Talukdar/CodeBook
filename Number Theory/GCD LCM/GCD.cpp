#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b)
{
    if(!a)
        return b;
    return gcd(b%a,a);
/*
    if(!a)
        return b;
    else if(!b)
        return a;
    else if(!(a%b))
       return b;
    else if(!(b%a))
        return a;
    else
    {
        while(b)
        {
            temp=b;
            b=a%b;
            a=temp;
        }
        return a;
    }
    */
}

int main()
{
    int a,b;
    cin>>a>>b;
    cout<<__gcd(a,b);
    //cout<<gcd(a,b)<<endl;
}
