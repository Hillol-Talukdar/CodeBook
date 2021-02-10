#include<iostream>
#include<algorithm>
using namespace std;
int n,i,c=1,j=0;

struct my
{
    int st;
    int en;
}as[1000];

bool cmp(my i1,my i2)
{
    return i1.en < i2.en;
}

int main()
{
    vector<int> ac;
    ac.push_back(0);
    cin>>n;
    for(i=0;i<n;i++)
        cin>>as[i].st>>as[i].en;
    sort(as,as+n,cmp);
    for(i=1;i<n;i++)
    {
        if(as[i].st>=as[j].en)
        {
            ac.push_back(i);
            c++;
            j=i;
        }
    }
    cout<<c<<endl;
    cout<<"No of activity will be taken : ";
    for(i=0;i<ac.size();i++)
        cout<<ac[i]<<" ";
    cout<<endl;
}
