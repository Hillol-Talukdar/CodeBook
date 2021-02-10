#include<bits/stdc++.h>
using namespace std;

bool twoPointer(int a[],int i,int j, int x)
{
    while(i<j)
    {
        if(a[i]+a[j]==x)
            return true;
        else if(a[i]+a[j]<x)
            i++;
        else
            j--;
    }
    return false;
}

int main()
{
    int a[1005],i,j,x,n;
    cin>>n>>x;
    for(i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    if(twoPointer(a,0,n-1,x))
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
}
