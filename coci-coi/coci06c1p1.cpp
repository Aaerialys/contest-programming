#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

int n,x;
set<int> num;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    fori(0,10)
    {
        cin>>x;
        num.insert(x%42);
    }
    cout<<num.size();
    return 0;
}