#include<bits/stdc++.h>
using namespace std;

double calcAngle(double h, double m)
{
    if(h==12)
        h=0;
    if(m==60)
        m=0;
    double hour_angle = 0.5*(h*60+m);
    double minute_angle = 6*m;
    double angle = abs(hour_angle - minute_angle);
    angle = min(360-angle, angle);
    return angle;
}

int main()
{
    int hour,minute;
    cin>>hour>>minute;
    cout<<calcAngle(hour,minute)<<endl;
}
