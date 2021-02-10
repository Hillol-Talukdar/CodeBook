#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[1000],n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);  //for Ascending order
 //  sort(a,a+n,greater<int>());    //for Descending order
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
    return 0;
}
