#include<bits/stdc++.h>
using namespace std;
int a[1000],n,i;
void merge(int b,int m,int e)
{
    int n1=m-b+1,n2=e-m,l=0,r=0;
    int L[n1+1],R[n2+1];
    for(i=0;i<n1;i++)
        L[i]=a[b+i];
    for(i=0;i<n2;i++)
        R[i]=a[m+1+i];
    L[n1]=INT_MAX;
    R[n2]=INT_MAX;
    for(i=b;i<=e;i++)
    {
        if(L[l]<=R[r])
            a[i]=L[l++];
        else
            a[i]=R[r++];
    }
}
void mergesort(int b,int e)
{
    int m;
    if(b<e)
    {
        m=(b+e)/2;
        mergesort(b,m);
        mergesort(m+1,e);
        merge(b,m,e);
    }
}
int main()
{
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    mergesort(0,n-1);
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
