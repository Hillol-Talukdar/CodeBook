#include<bits/stdc++.h>
using namespace std;

bool dp[100][100];

void display(const vector<int>& vc)
{
    for(auto it: vc)
        cout<<it<<" ";
    cout<<endl;
}

void printSubsetsRec(int a[], int n, int sum, vector<int> & vc)
{
    if(!n && sum && dp[0][sum])
    {
        vc.push_back(a[n]);
        display(vc);
        return;
    }

    if(!n && !sum)
    {
        display(vc);
        return;
    }

    if(dp[n-1][sum])
    {
        vector<int> vc2 = vc;
        printSubsetsRec(a,n-1, sum , vc2);
    }

    if(sum>=a[n] && dp[n-1][sum-a[n]])
    {
        vc.push_back(a[n]);
        printSubsetsRec(a,n-1, sum-a[n], vc);
    }
}

void printAllSubsets(int a[], int n, int sum)
{
    if(!n || sum<0)
        return;

    for(int i=0;i<=n;i++)
        dp[i][0]= true;

    if(a[0]<=sum)
        dp[0][a[0]] = true;

    for(int i=1;i<n;i++)
        for(int j=0;j<=sum;j++)
            dp[i][j] = (a[i]<=j) ? dp[i-1][j] || dp[i-1][j-a[i]] : dp[i-1][j];

    if(dp[n-1][sum] == false)
    {
        cout<<"There are no subset with sum : "<<sum<<endl;
        return;
    }

    vector<int> vc;
    printSubsetsRec(a,n-1,sum,vc);
}

int main()
{
    int a[1005],n,sum;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cin>>sum;

    printAllSubsets(a,n,sum);
}
