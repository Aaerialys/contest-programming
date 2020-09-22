#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

int n,m,len[100];
string s;
priority_queue<pair<int,int>> x;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    fori(0,n)
    {
        cin>>s;
        len[i]=s.size();
    }
    cin>>m;
    fori(0,m)
        x.push({0,-i-1});
    fori(0,n)
    {
        cout<<-x.top().second<<endl;
        x.push({x.top().first-len[i],x.top().second});
        x.pop();
    }
    return 0;
}