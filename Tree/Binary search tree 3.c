#include<stdio.h>
int main()
{
    int a[1000],n,i,j,temp,b[1000],max=0;
    memset(a,-1,sizeof(a));
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&b[i]);
    for(i=1;i<=n;i++)
    {
        for(j=1; ;j++)
        {
            if(a[j]==-1)
                break;
            else if(b[i]<a[j])
                j*=2;
            else
                j=(j*2)+1;
        }
        a[j]=b[i];
        if(j>max)
            max=j;
    }
    for(i=1;i<=max;i++)
        printf("%d ",a[i]);
    printf("\n");
}
