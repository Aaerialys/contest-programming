#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("DATA41.txt", "r", stdin);
    fork(0,10)
    {
        stack<pair<long long,long long>> stop;
        long long n,r,s,t,x,y;
        cin>>n>>r>>s; s+=r; stop.push({INT_MAX,-1000001}); t=0;
        fori(0,n)
        {
            cin>>x; y=0;
            while(stop.top().first<=x)
            {
                t+=min(s,(i-stop.top().second)*r)*(stop.top().first-y);
                y=stop.top().first;
                stop.pop();
            }
            t+=min(s,(i-stop.top().second)*r)*(x-y);
            stop.push({x,i});
        }
        cout<<t<<endl;
    }
    return 0;
}
/*
4 1 2
2 1 1 2
*/