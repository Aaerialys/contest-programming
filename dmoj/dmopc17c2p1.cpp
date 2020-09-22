#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    long long n,sum=0,w,v;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>w>>v;
        if(v>0)
            sum+=w;
    }
    cout<<sum;
    return 0;
}