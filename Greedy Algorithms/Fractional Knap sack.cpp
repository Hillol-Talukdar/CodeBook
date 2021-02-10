#include<iostream>
#include<algorithm>
using namespace std;
int max_weight,i,n;
double price=0.0;

typedef struct my
{
    double price;
    int weight;
    double ppw;
};
my st[1000];

bool cmp(my i1,my i2)
{
    return i1.ppw>i2.ppw;
}

void fks()
{
    for(i=0;i<n;i++)
    {
        if(max_weight<=0)
            break;
        else if(st[i].weight<max_weight)
        {
            price+=st[i].price;
            max_weight-=st[i].weight;
        }
        else
        {
            price+=max_weight*st[i].ppw;
            max_weight=0;
        }
    }
    cout<<price<<endl;
}

int main()
{
    cin>>n>>max_weight;
    for(i=0;i<n;i++)
    {
        cin>>st[i].price>>st[i].weight;
        st[i].ppw=st[i].price/st[i].weight;
    }
    sort(st,st+n,cmp);
    fks();
}
