#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n,t=0,x=0;
    cin>>n;
    pair<int,int> hw[n];
    fori(0,n)
    {
        cin>>hw[i].first>>hw[i].second;
    }
    sort(hw,hw+n);
    reverse(hw,hw+n);
    priority_queue<int> imp;
    fori(0,n)
    {
        while(x<n&&hw[x].first==n-i)
        {
            imp.push(hw[x].second);
            x++;
        }
        if(!imp.empty())
        {
            t+=imp.top();
            imp.pop();
        }
    }
    cout<<t;
    return 0;
}