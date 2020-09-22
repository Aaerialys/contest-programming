#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

stack<pair<int,int>> line;
int n,x,y;
long long t;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    fori(0,n)
    {
        cin>>x; y=1;
        while(!line.empty()&&line.top().first<x)
        {
            t+=line.top().second;
            line.pop();
        }
        if(!line.empty()&&line.top().first==x)
        {
            t+=line.top().second;
            y+=line.top().second;
            line.pop();
        }
        if(!line.empty())
            t++;
        line.push({x,y});
    }
    cout<<t;
    return 0;
}