#include<bits/stdc++.h>
using namespace std;
string a,b;

int lcs(int i,int j)
{
    if(!i || !j)
        return 0;
    else if(a[i-1]==b[j-1])
        return 1+lcs(i-1,j-1);
    return max(lcs(i,j-1) ,lcs(i-1,j));
}

int main()
{
    cin>>a>>b;
    cout<<"LCS : "<<lcs(a.size(),b.size());
}

/*
abcbdab
bdcaba

*/
