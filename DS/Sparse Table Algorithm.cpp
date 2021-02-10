#include <bits/stdc++.h>
using namespace std;

const int Max = 1e5+10;
const int lgMax = log2(Max)+1;
int sparse[Max][lgMax], Log[Max];// sparse[Max][Max][lgMax]

void buildLog()
{
    for(int i=2;i<=Max;i++)
        Log[i] = Log[i/2] + 1;
}

void buildSparseTable(int a[], int n)
{
    int i,j;

    for(i=0;i<n;i++)
        sparse[i][0] = a[i];

    for(j=1; (1<<j) <=n ;j++)   //for(j=1; j <=Log[n] ;j++)
        for(i=0; i+(1<<j)-1 < n ;i++)
            sparse[i][j] = min( sparse[i][j-1] , sparse[ i + (1<<(j-1)) ][j-1] );
          //  sparse[i][j] = __gcd( sparse[i][j-1], sparse[i + (1<<(j-1)) ][j - 1]);
}

int query(int L, int R)
{
    int k= Log[R-L+1];  //k = (int) log2(R-L+1);
    return min( sparse[L][k] , sparse[R - (1<<k) +1][k] );
}

/*
void buildSparseTable(int a[], int n, int row)  //2d Sparse Table
{
    int i,j;

    for(i=0;i<n;i++)
        sparse[row][i][0] = a[i];

    for(j=1; (1<<j) <=n ;j++)
        for(i=0; i+(1<<j)-1 < n ;i++)
            sparse[row][i][j] = max( sparse[row][i][j-1] , sparse[row][ i + (1<<(j-1)) ][j-1] );
}

int query(int row, int L, int R)
{
    int k= Log[R-L+1];
    return max( sparse[row][L][k] , sparse[row][R - (1<<k) +1][k] );
}
*/

int main()
{
    buildLog();

    int n,a[Max],q,l,r;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    buildSparseTable(a, n);

   /* for(int i=0;i<n;i++)
    {
        for(int j=0,j<n;j++)
            cin>>a[j];
        buildSparseTable(a, n, i);
    }*/

    cin>>q;
    while(q--)
    {
        cin>>l>>r;
        cout<<query(l,r)<<endl;

        /*cin>>x;
        int mn=INT_MAX;
        for(int i=l;i<=l+x-1;i++)
                mx = min(mx, query(i, r, r+x-1));
        cout<<mn<<endl;*/
    }
}
