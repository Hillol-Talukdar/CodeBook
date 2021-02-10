#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[1000],sum[1000],i,j,n;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        sum[0]=a[0];
        for(i=1;i<n;i++)
            sum[i]=sum[i-1]+a[i];
        for(i=0;i<n;i++)
            printf("%d ",sum[i]);
        printf("\n");
    }
    return 0;
}
