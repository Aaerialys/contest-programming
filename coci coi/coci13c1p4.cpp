#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    long long n,k,t=0,j=0;
    cin>>n>>k;
    int hold[k];
    pair<int,int> jew[n];
    priority_queue<int> mabv;
    fori(0,n)
    {
        cin>>jew[i].first>>jew[i].second;
    }
    fori(0,k)
    {
        cin>>hold[i];
    }
    sort(hold,hold+k);
    sort(jew,jew+n);
    fori(0,k)
    {
        for(;j<n&&jew[j].first<=hold[i];j++)
        {
            mabv.push(jew[j].second);
        }
        if(!mabv.empty())
        {
            t+=mabv.top();
            mabv.pop();
        }
    }
    cout<<t;
    return 0;
}