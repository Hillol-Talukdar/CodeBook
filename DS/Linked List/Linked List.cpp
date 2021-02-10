#include<bits/stdc++.h>
using namespace std;
typedef struct my{
                  int data;
                  my *next;
}node;

void insert(node *s,int data)
{
    while(s->next!=NULL)
    {
        s=s->next;
    }
    s->next=(node*) malloc(sizeof(node));
    s->next->data = data;
    s->next->next = NULL;
}

void display(node *s)
{
    if(s->next==NULL)
        cout<<"Empty List"<<endl;
    while(s->next != NULL)
    {
        cout<<"Data :"<<s->next->data<<endl;
        s=s->next;
    }
}

int dlt(node *s,int data)
{
    if(s->next==NULL)
        cout<<"Empty List"<<endl;
    while(s->next != NULL)
    {
        if(s->next->data == data)
        {
            s->next = s->next->next;
            return 0;
        }
        s=s->next;
    }
}

void srch(node *s,int data)
{
    int count=0;
    if(s->next==NULL)
        cout<<"Empty List"<<endl;
    while(s->next != NULL)
    {
        if(s->next->data == data)
        {
            count++;
        }
        s=s->next;
    }
    if(count>0)
        cout<<data<<" found and number of repeat "<<count-1<<endl;
    else
        cout<<"Data Not Found!!"<<endl;
}

int main()
{
    string st;
    node *first = (node*) malloc(sizeof(node));
    first->next = NULL;
    while(1)
    {
        int a;
        cin>>st;
        if(!st.compare("insert"))
        {
            cin>>a;
            insert(first,a);
        }
        else if(!st.compare("display"))
            display(first);
        else if(!st.compare("delete"))
        {
            cin>>a;
            dlt(first,a);
        }
        else if(!st.compare("search"))
        {
            cin>>a;
            srch(first,a);
        }
    }
}
