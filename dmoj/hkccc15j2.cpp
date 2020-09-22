#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n,m=INT_MAX;
    cin>>n;
    int x[n];
    int y[n];
    for(int i=0;i<n;i++)
    {
        cin>>x[i]>>y[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(max(pow(x[i]-x[j],2),pow(y[i]-y[j],2))<m&&j!=i)
                m=max(pow(x[i]-x[j],2),pow(y[i]-y[j],2));
        }
    }
    cout<<m;
    return 0;
}