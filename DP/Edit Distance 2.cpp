#include<bits/stdc++.h>
using namespace std;

string a,b;

int ed(int len,int l)
{
    if(!len)
        return l;
    else if(!l)
        return len;
    else if(a[len-1]==b[l-1])
        return ed(len-1,l-1);
    return 1+ min( min(ed(len-1,l-1), ed(len-1,l) ), ed(len,l-1));
}

int main()
{
    cin>>a>>b;
    cout<<"ED : "<<ed(a.size(),b.size())<<endl;
}

/*
gambol
gumbo

*/

