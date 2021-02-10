#include<bits/stdc++.h>
using namespace std;

typedef struct my
{
    int data;
    my *next;
}node;

void insert(node *n,int data)
{
    while(n->next!= NULL)
        n=  n->next;
    n->next= (node*) malloc(sizeof(node));
    n->next->next= NULL;
    n->next->data= data;
}

void del(node *n,int data)
{
    if(n->next ==NULL)
        cout<<"Empty List!"<<endl;
    else
    {
        int p=0,data;
        cin>>data;
        while(n->next!= NULL)
        {
            if(n->next->data== data)
            {
                p=1;
                n->next= n->next->next;
                break;
            }
            n= n->next;
        }
        if(!p)
            cout<<"Invalid Number!"<<endl;
    }
}

void show(node *n,int data)
{
    if(n->next== NULL)
        cout<<"Empty List!"<<endl;
    while(n->next!= NULL)
    {
        cout<<"Data : "<<n->next->data<<endl;
        n= n->next;
    }
}

void search(node *n,int data)
{
    if(n->next== NULL)
        cout<<"List Empty!"<<endl;
    int count=0;
    while(n->next!= NULL)
    {
        if(n->next->data== data)
            count++;
        n= n->next;
    }
    if(count)
        cout<<"Item found!"<<endl<<"Number of item & repeated in the list : "<<count<<" & "<<count-1<<endl;
    else
        cout<<"Item not found!"<<endl;
}

int main()
{
    string s;
    node *first=(node*) malloc(sizeof(node));
    first->next= NULL;
    while(1)
    {
        int a;
        cin>>s;
        if(!s.compare("insert"))
        {
            cin>>a;
            insert(first,a);
        }
        else if(!s.compare("delete"))
            del(first,a);
        else if(!s.compare("show"))
            show(first,a);
        else if(!s.compare("search"))
        {
            cin>>a;
            search(first,a);
        }
    }
}
