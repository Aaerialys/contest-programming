#include <bits/stdc++.h>
#define fori(a,b) for(long long i=a;i<b;i++)
#define forj(a,b) for(long long j=a;j<b;j++)
#define fork(a,b) for(long long k=a;k<b;k++)
#define ford(i,a,b) for(long long i=a;i>=b;i--)

using namespace std;

long long n,w,x,y;
char ch;
vector<long long> loc,c;
priority_queue<long long> cutest,r;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>w;
    c.push_back(0); loc.push_back(0); cutest.push(0); r.push(-1);
    fori(0,n)
    {
        cin>>ch;
        if(ch=='A')
        {
            while(r.top()==cutest.top())
            {
                r.pop();
                cutest.pop();
            }
            cin>>x>>y;
            loc.push_back(loc.back()+x);
            c.push_back(c.back()+y);
            cutest.push(c.back()-c[lower_bound(loc.begin(),loc.end(),loc.back()-w)-loc.begin()]);
            cout<<cutest.top()<<"\n";
        }
        if(ch=='D')
        {
            r.push(c.back()-c[lower_bound(loc.begin(),loc.end(),loc.back()-w)-loc.begin()]);
            loc.pop_back();
            c.pop_back();
        }
    }
    return 0;
}