#include<bits/stdc++.h>
using namespace std;


int  binary_representation(int n)   //for counting 1
{
    int cnt=0;
    while(n>0)
    {
        cnt++;
        n&=(n-1);
       // cnt+=(n % 2);
      //  n/= 2;
    }
    return cnt;
}
/*
void binary_representation(int n)
{
    if(n>1)
        binary_representation(n/2);

    cout<<n%2;
}
*/
int main()
{
    int T,n;
    cin>>T;
    while(T--)
    {
        cin>>n;
        int dec_bin=binary_representation(n);
      //  binary_representation(n);
        puts("");
    }
}

