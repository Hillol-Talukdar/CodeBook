#include<bits/stdc++.h>
using namespace std;

const int SZ = 26;
char ch='a';

struct node
{
    bool endmark;
    node* next[SZ];
    node()
    {
        endmark = false;
        for(int i=0;i<SZ;i++)
            next[i] = NULL;
    }
}*root;

void insert(string s, int len)
{
    node* cur = root;
    for(int i=0;i<len;i++)
    {
        int id = s[i] - ch;
        if(cur->next[id] == NULL)
            cur->next[id] = new node();
        cur = cur->next[id];
    }
    cur->endmark = true;
}

bool search(string s, int len)
{
    node* cur = root;
    for(int i=0;i<len;i++)
    {
        int id = s[i] - ch;
        if(cur->next[id] == NULL)
            return false;
        cur = cur->next[id];
    }
    return cur->endmark;
}

bool isEmpty(node* cur)
{
    for(int i=0;i<SZ;i++)
        if(cur->next[i])
            return false;
    return true;
}

node* remove(node* cur, string s, int depth = 0)
{
    if(!cur)
        return NULL;
    if(depth == s.size())
    {
        if(cur->endmark)
            cur->endmark = false;
        if(isEmpty(cur))
        {
            delete (cur);
            cur = NULL;
        }
        return cur;
    }
    int id = s[depth] - ch;
    cur->next[id] = remove(cur->next[id], s, depth+1);

    if(isEmpty(cur) && !cur->endmark)
    {
        delete (cur);
        cur = NULL;
    }
    return cur;
}

void del(node* cur)
{
    for(int i=0;i<SZ;i++)
        if(cur->next[i])
            del(cur->next[i]);
    delete (cur);
}

int main()
{
    root = new node();
    int n,q;
    string s;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        insert(s, s.size());
    }
    cin>>q;
    while(q--)
    {
        cin>>s;
        if(search(s , s.size()))
            puts("FOUND");
        else
            puts("NOT FOUND");
    }
    del(root);
}
