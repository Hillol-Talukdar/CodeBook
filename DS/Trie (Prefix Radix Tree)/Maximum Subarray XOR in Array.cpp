#include<bits/stdc++.h>
using namespace std;

const int Max = 1e5+5;
const int SZ = 2;
const int bit_SZ = 31;

struct node
{
    int endmark;
    node* next[SZ];
    node()
    {
        endmark = 0;
        for(int i=0;i<SZ;i++)
            next[i] = NULL;
    }
}*root;

void insert(int pre_xor)
{
    node* cur = root;
    for(int i=bit_SZ;i>=0;i--)
    {
        bool id = pre_xor & (1<<i);
        if(cur->next[id] == NULL)
            cur->next[id] = new node();
        cur = cur->next[id];
    }
    cur->endmark = pre_xor;
}

int query(int pre_xor)
{
    node* cur = root;
    for(int i=bit_SZ;i>=0;i--)
    {
        bool id = pre_xor & (1<<i);
        if(cur->next[1-id] != NULL)
            cur = cur->next[1-id];
        else if(cur->next[id] != NULL)
            cur = cur->next[id];
    }
    return pre_xor ^ (cur->endmark);
}

void del(node* cur)
{
    for(int i=0;i<SZ;i++)
        if(cur->next[i])
            del(cur->next[i]);
    delete (cur);
}

int maxSubarrayXOR(int a[], int n)
{
    root = new node();
    insert(0);

    int res = INT_MIN , pre_xor = 0;

    for(int i=0;i<n;i++)
    {
        pre_xor = pre_xor ^ a[i];
        insert(pre_xor);

        res = max({res , a[i], query(pre_xor)});
    }
    return res;
}

int main()
{
    int T,n,a[Max];
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<maxSubarrayXOR(a, n)<<endl;
    del(root);
}
