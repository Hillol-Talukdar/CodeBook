#include<bits/stdc++.h>
using namespace std;
int a[1000],n,i,q,j;
int partition(int b,int e)
{
    int i=b-1,x=a[e];
    for(j=b;j<e;j++)
        if(a[j]<=x)     //for descending order a[j]>=x
            swap(a[++i],a[j]);
    swap(a[i+1],a[e]);
    return i+1;
}
void quicksort(int b,int e)
{
    if(b<e)
    {
        q=partition(b,e);
        quicksort(b,q-1);
        quicksort(q+1,e);
    }
}
int main()
{
    ios_base:: sync_with_stdio(false);
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    quicksort(0,n-1);
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
