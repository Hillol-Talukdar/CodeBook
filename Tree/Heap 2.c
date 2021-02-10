#include<stdio.h>
int main()
{
    int a[1000],n,i,j,p,temp;
    memset(a,-1,sizeof(a));
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(i>1)
        {
            p=i;
            while(1)
            {
                if(a[p/2]<a[p] && (p/2)>0)
                {
                    temp=a[p];
                    a[p]=a[p/2];
                    a[p/2]=temp;
                    p/=2;
                }
                else
                    break;
            }
        }
    }
    for(i=1;i<=n;i++)
        printf("%d ",a[i]);
    printf("\n");
}
