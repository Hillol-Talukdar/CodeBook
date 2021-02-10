#include<bits/stdc++.h>
using namespace std;

int getMaxArea_in_Histogram(int a[], int n)
{
    stack<int> st;
    int max_area=0,tp,area_with_top,i=0;
    while(i<n)
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

int main()
{
    int a[1000],n,i;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    cout << "Maximum area is " << getMaxArea_in_Histogram(a, n)<<endl;
}


// https://www.geeksforgeeks.org/largest-rectangle-under-histogram/
