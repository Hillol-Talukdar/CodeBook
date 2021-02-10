#include<bits/stdc++.h>
using namespace std;

void combinationUtil(int arr[], int data[], int start, int end, int index,int r)
{
    if(index==r)
    {
        for (int j = 0; j < r; j++)
            cout << data[j] << " ";
        cout << endl;
        return;
    }
    for(int i=start;i<=end && end-i+1>= r-index;i++)
    {
        data[index]=arr[i];
        combinationUtil(arr, data, i+1, end, index+1, r);
    }
}

void printCombination(int arr[], int n, int r)
{
    int data[r];
    combinationUtil(arr, data, 0, n-1, 0, r);
}

int main()
{
    int arr[1000],r,n,i;
    cin>>n>>r;
    for(i=0;i<n;i++)
        cin>>arr[i];
    printCombination(arr, n, r);
}
