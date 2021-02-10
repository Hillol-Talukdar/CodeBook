#include<bits/stdc++.h>
using namespace std;
int main(){
    int  n;
    double fac=0;
    cin>>n;
    for(int i=1;i<=n;i++)
        fac+=log2(i);
    fac=pow(2, fac);
    cout<<fac<<endl;
}

