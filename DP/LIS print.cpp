#include<bits/stdc++.h>
using namespace std;

int a[1005],tail_idx[1005],prev_idx[1005],dp[1005],n;

void display(int len)
{
    if(len == -1)
        return;
    display(prev_idx[len]);
    cout<<a[len]<<" ";
}

void lis_print()
{
    int len=0 , l_end=0;

    memset(dp,0,sizeof(dp));
    memset(tail_idx,0,sizeof(tail_idx));
    memset(prev_idx,-1,sizeof(prev_idx));

    for(int i=0;i<n;i++)
    {
        int idx = lower_bound(dp,dp+len,a[i]) - dp;
        dp[idx] = a[i];
        tail_idx[idx] = i;
        prev_idx[i] = idx>0 ? tail_idx[idx-1] : -1;
        if(idx == len)
            len++, l_end = i;
    }
    cout<<"LIS : ";
    if(len)
        display(l_end);
    cout<<endl;
}

/*
int bs(int lo, int hi, int val)
{
    while(hi-lo > 1)
    {
        int mid = lo + (hi-lo)/2;
        if(a[tail_idx[mid]] >= val)
            hi = mid;
        else
            lo = mid;
    }
    return hi;
}

void lis_print()   //O(nlog(n))
{
    if(!n)
       return;     // return 0 for length

    int len=1;
    memset(tail_idx,0,sizeof(tail_idx));
    memset(prev_idx,-1,sizeof(prev_idx));

    for(int i=1;i<n;i++)
    {
        if(a[i] < a[tail_idx[0]])
            tail_idx[0] = i;
        else if(a[i] > a[tail_idx[len-1]])
        {
            prev_idx[i] = tail_idx[len-1];
            tail_idx[len++] = i;
        }
        else
        {
            int idx = bs(-1, len-1, a[i]);
            prev_idx[i] = tail_idx[idx-1];
            tail_idx[idx] = i;
        }
    }
    cout<<"LIS : ";
    display(tail_idx[len-1]);

//    for(int i=tail_idx[len-1] ; i>=0 ; i= prev_idx[i])
//        cout<<a[i]<<" ";
    cout<<endl;
  //  return len;
}
*/

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    lis_print();
}
