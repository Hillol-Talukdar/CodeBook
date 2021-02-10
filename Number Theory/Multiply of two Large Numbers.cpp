#include<bits/stdc++.h>
using namespace std;

string multiply(string s, string s2)
{
    int len1= s.size(), len2= s2.size(), i_n1=0, i_n2;
    string ans;
    if(!len1 || !len2)
        return "0";

    vector<int> result(len1 + len2, 0);

    for(int i=len1-1;i>=0;i--)
    {
        int carry=0, n1= s[i]-'0';
        i_n2=0;
        for(int j=len2-1;j>=0;j--)
        {
            int n2= s2[j]-'0';
            int sum = n1*n2 + result[i_n1 + i_n2] + carry;
            carry = sum/10;
            result[i_n1 + i_n2] = sum%10;
            i_n2++;
        }
        if(carry)
            result[i_n1 + i_n2] += carry;
        i_n1++;
    }
    int len3=result.size()-1;
    while(len3>=0 && result[len3]==0)
        len3--;

    if(len3==-1)
        return "0";

    while(len3>=0)
        ans+= to_string(result[len3--]);

    return ans;
}

int main()
{
    string s,s2;
    cin>>s>>s2;
    if((s[0]=='-' || s2[0]=='-') && (s[0]!='-' || s2[0]!='-' ))
        cout<<"-";
    if(s[0]=='-' && s2[0]!='-')
        s = s.substr(1);
    else if(s[0]!='-' && s2[0]=='-')
        s2 = s2.substr(1);
    else if(s[0]=='-' && s2[0]=='-')
    {
        s = s.substr(1);
        s2 = s2.substr(1);
    }
    cout<<multiply(s,s2)<<endl;
}
