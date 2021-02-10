#include<bits/stdc++.h>
using namespace std;

string findsum(string s1, string s2)
{
    int len=s1.size(), l2=s2.size(),i,carry=0,sum;
    string ans;
    if(len>l2)     // len must be equal or less than l2
    {
        swap(s1,s2);
        swap(len,l2);
    }
    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());

    for(i=0;i<len;i++)
    {
        sum= (s1[i]-'0') + (s2[i]-'0') + carry;
        ans+= (sum%10) + '0';
        carry= sum/10;
    }

    for(i=len;i<l2;i++)
    {
        sum=(s2[i]-'0') + carry;
        ans+= (sum%10) +'0';
        carry= sum/10;
    }
    if(carry)
        ans+=carry+'0';
    reverse(ans.begin(),ans.end());
    return ans;
}

int main()
{
    string s,s2;
    cin>>s>>s2;
    cout<<findsum(s,s2);
}
