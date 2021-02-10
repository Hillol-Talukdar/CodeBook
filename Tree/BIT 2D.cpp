#include <bits/stdc++.h>
using namespace std;

const int Max = 1e3 + 5;

int BIT[Max][Max] , n = Max;

void update(int x,int y)
{
    while(x <= n)
    {
        int idx = y;
        while(idx <= n)
        {
            BIT[x][idx]++;
            idx += idx & -idx;
        }
        x += x & -x;
    }
}

void build()
{
    memset(BIT,0,sizeof(BIT));
}

int query(int x,int y)
{
    int ret = 0;
    while(x > 0)
    {
        int idx = y;
        while(idx > 0)
        {
            ret += BIT[x][idx];
            idx -= idx & -idx;
        }
        x -= x & -x;
    }
    return ret;
}

int query(int x, int y, int x1, int y1)
{
    // (x,y) is  lower left; (x1,y1) is upper-right
    return query(x1,y1) - query(x1,y-1) - query(x-1,y1) + query(x-1,y-1);
}

