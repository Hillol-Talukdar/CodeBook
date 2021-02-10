#include<stdio.h>
int a[100][100],i,j,k,n,big=5000;
void floyedwarshall()
{
    for(k=0;k<n;k++)
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                if( (a[i][k]+a[k][j]) < a[i][j])
                    a[i][j]=a[i][k]+a[k][j];
}
int main()
{
    scanf("%d",&n);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            scanf("%d",&a[i][j]);
            if(a[i][j]==0)
                a[i][j]=big;
        }
    floyedwarshall();
    printf("\n\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[i][j]==big)
                printf("N ");
            else
                printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}
