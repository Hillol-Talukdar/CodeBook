#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[1000],n,i,count[1000],j=0,mx=INT_MIN,mn=INT_MAX,temp;
    memset(count,0,sizeof(count));
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        count[a[i]]++;
        mx=max(a[i],mx);
        mn=min(a[i],mn);
    }
    for(i=mn;i<=mx;i++)
    {
        if(count[i]>0)
        {
            temp=count[i];
            while(temp--)
                a[j++]=i;
        }
    }
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
    return 0;
}
