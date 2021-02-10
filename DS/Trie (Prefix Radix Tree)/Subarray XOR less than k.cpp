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
        cur->endmark++;
    }
}

int get(node* cur)
{
    return cur ? cur->endmark : 0;
}

int query(int pre_xor , int k)
{
    node* cur = root;
    int res=0;
    for(int i=bit_SZ;i>=0;i--)
    {
        if(!cur)
            break;
        bool pre_bit = pre_xor & (1<<i);
        bool k_bit = k & (1<<i);

        if(pre_bit == k_bit)
        {
            if(pre_bit == 1)
                res += get(cur->next[1]);
            cur = cur->next[0];
        }
        else
        {
            if(pre_bit == 0)
                res += get(cur->next[0]);
            cur = cur->next[1];
        }
    }
    return res;
}

void del(node* cur)
{
    for(int i=0;i<SZ;i++)
        if(cur->next[i])
            del(cur->next[i]);
    delete (cur);
}

int SubarrayXOR(int a[], int n, int k)
{
    root = new node();
    insert(0);

    int res = 0 , pre_xor = 0;

    for(int i=0;i<n;i++)
    {
        pre_xor = pre_xor ^ a[i];
        res += query(pre_xor, k);
        insert(pre_xor);
    }
    return res;
}

int main()
{
    int n,k,a[Max];
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>a[i];
    cout<<SubarrayXOR(a, n, k)<<endl;
    del(root);
}



