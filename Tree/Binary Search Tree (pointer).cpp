#include<bits/stdc++.h>
using namespace std;

long long b,e,mid,t,n,resume,ans;

typedef struct my
{
    int data;
    my *left,*right;
};

my* creatnode(int data)
{
    my *temp = new my();
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

my* insert(my *root,int data)
{
    if(root==NULL)
        return creatnode(data);
    if(root->data > data)
        root->left = insert(root->left, data);
    else if(root->data < data)
        root->right = insert(root->right, data);
    return root;
}

void displayin(my *root)
{
    if(root)
    {
        displayin(root->left);
        cout<< root->data <<endl;
        displayin(root->right);
    }
}

void displaypre(my *root)
{
    if(root)
    {
        cout<<  root->data <<endl;
        displaypre(root->left);
        displaypre(root->right);
    }
}

void displaypost(my *root)
{
    if(root)
    {
        displaypost(root->left);
        displaypost(root->right);
        cout<<  root->data <<endl;
    }
}

long long depth(my *root)
{
    if(root==NULL)
        return 0;
    int left = depth(root->left);
    int right = depth(root->right);
    return (left,right)+1;
}

int main()
{
    string s;
    int a,n,i,ans;
    my *root=NULL,*temp;
    while(cin>>s)
    {
        if(!s.compare("insert"))
        {
            cout<<"Number of  element : ";
            cin>>n;
            cin>>a;
            root= creatnode(a);
            for(i=2;i<=n;i++)
            {
                cin>>a;
                insert(root,a);
            }
        }
        else if(!s.compare("depth"))
            cout<< depth(root)<<endl;
        else if(!s.compare("pre"))
            displaypre(root);
        else if(!s.compare("post"))
            displaypost(root);
        else if(!s.compare("in"))
            displaypre(root);
    }
}
