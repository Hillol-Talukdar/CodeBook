#include<bits/stdc++.h.>
using namespace std;
int main()
{
    int a[1000],n,i,j,temp;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=1;i<n;i++)
    {
        temp=a[i];
        j=i-1;
        while(j>=0 && a[j]>temp)
            a[j+1]=a[j--];
        a[j+1]=temp;
    }
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}
