#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

int n,m,x;
priority_queue<int> least;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    fori(0,n)
    {
        cin>>x;
        least.push(-x);
    }
    fori(0,m)
    {
        cout<<-least.top()<<"\n";
        least.push(least.top()-1);
        least.pop();
    }
    return 0;
}