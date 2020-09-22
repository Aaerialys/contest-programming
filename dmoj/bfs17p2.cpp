#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n,m=0,t=0;
    int c[6]={0};
    string col;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>col;
        if (col=="red")
            c[0]++;
        if (col=="orange")
            c[1]++;
        if (col=="yellow")
            c[2]++;
        if (col=="green")
            c[3]++;
        if (col=="blue")
            c[4]++;
        if (col=="black")
            c[5]++;
    }
    for(int i=0;i<6;i++)
    {
        t+=c[i];
        if(m<c[i])
            m=c[i];
    }
    cout<<t-m+min(t+1-m,m);
    return 0;
}