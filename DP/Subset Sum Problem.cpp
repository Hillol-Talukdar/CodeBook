#include<bits/stdc++.h>
using namespace std;
/*
bool isSubsetSum(int a[], int n, int sum)
{
    if(!sum)
        return true;
    if(!n && sum)
        return false;
    if(a[n-1]>sum)
        return isSubsetSum(a, n-1, sum);
    return isSubsetSum(a, n-1, sum) || isSubsetSum(a, n-1, sum - a[n-1]);
}
*/


bool isSubsetSum(int a[], int n, int sum)
{
    bool dp[n+1][sum+1];

    for(int i=0;i<=n;i++)
        dp[i][0]=true;
    for(int i=1;i<=sum;i++)
        dp[0][i]=false;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(j-a[i-1] >= 0)
                dp[i][j] = dp[i-1][j] || dp[i-1][j-a[i-1]];
            else
                dp[i][j] = dp[i-1][j];
        }
    }


//    int i=n,j=sum;    //    subsetPrint
//    vector<int> vc;
//    while(i>0 && j>0)
//    {
//        if(dp[i][j]==true)
//        {
//            if(dp[i-1][j]==true)
//                i--;
//            else
//            {
//                vc.push_back(a[i-1]);
//                j-=a[i-1];
//            }
//        }
//    }
//    for(auto it:vc)
//        cout<<it<<" ";
//    cout<<endl;


    return dp[n][sum];
}

bool Partition(int a[],int n)
{
    int sum=accumulate(a,a+n,0);

    if(sum&1)
        return false;
    sum/=2;
    bool can_partition = isSubsetSum(a,n,sum);
    return can_partition;
}

int main()
{
    int a[1005],n,sum;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cin>>sum;

    if(Partition(a,n))
        cout<<"Can be partitioned"<<endl;
    else
        cout<<"Can't be partitioned"<<endl;

    if(isSubsetSum(a,n,sum))
        cout<<"Found a subset with given sum"<<endl;
    else
        cout<<"No subset with given sum"<<endl;
}
