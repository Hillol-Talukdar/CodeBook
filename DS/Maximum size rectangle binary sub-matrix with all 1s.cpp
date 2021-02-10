#include<bits/stdc++.h>
using namespace std;

int dp[100][100],r,c,i,j;

int getMaxArea_in_Histogram(int a[])
{
    stack<int> st;
    int max_area=0,tp,area_with_top,i=0;
    while(i<c)
    {
        if (st.empty() || a[st.top()] <= a[i])
            st.push(i++);
        else
        {
            tp = st.top();
            st.pop();
            area_with_top = a[tp] * (st.empty() ? i : i-st.top()-1 );

            max_area = max(max_area,area_with_top);
        }
    }

    while (!st.empty())
    {
        tp = st.top();
        st.pop();
        area_with_top = a[tp] * (st.empty() ? i : i-st.top()-1 );

        max_area = max(max_area,area_with_top);
    }
    return max_area;
}

int maxRectangle()
{
    int result = getMaxArea_in_Histogram(dp[0]);
    for(i=1;i<r;i++)
    {
        for(j=0;j<c;j++)
            if(dp[i][j])
                dp[i][j]+=dp[i-1][j];

        result=max(result,getMaxArea_in_Histogram(dp[i]));
    }
    return result;
}

int main()
{
    cin>>r>>c;
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            cin>>dp[i][j];
    cout<<"Area of maximum rectangle is "<<maxRectangle()<<endl;
}
