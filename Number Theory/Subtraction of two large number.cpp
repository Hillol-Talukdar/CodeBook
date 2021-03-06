#include <bits/stdc++.h>
using namespace std;

int cmp(string a, string b)
{
    int i,l=a.size();

    if(a.size() > b.size())
        return 1;
    if(a.size() < b.size())
        return -1;
    else
    {
        for(i=0;i<l;i++)
        {
            if(a[i] > b[i])
                return 1;
            if(b[i] > a[i])
                return -1;
        }
        return 0;
    }
}

string strsub(string x, string y)
{
    string ans;
    int i,j,flag=0,l,ll;

    if(cmp(x, y)==0)
        return "0";

    if(cmp(x,y)==-1)
    {
        flag = 1;
        swap(x, y);
    }

    l=x.size(), ll=y.size();

    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());

    for(i=ll;i<l;i++)
        y += "0";

    for(i=0;i<l;i++)
    {
        if(x[i] < y[i])
        {
            j = i+1;
            while( x[j]=='0' && j<l)
            {
                x[j]='9';
                j++;
            }
            x[j]--;
            x[i]+=10;
        }
        ans += (x[i] - y[i]) % 10 + '0';
    }

    while(ans[l-1]=='0')
    {
        ans.erase(ans.end()-1);
        l--;
    }

    if(flag)
        ans += "-";

    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    string a,b;
    cin>>a>>b;
    cout<<strsub(a, b)<<endl;
}
