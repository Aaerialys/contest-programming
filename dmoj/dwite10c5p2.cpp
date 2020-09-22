#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

unordered_set<int> x,y;
int n,X,Y,a,b;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    fork(0,5)
    {
        cin>>X>>Y>>n; x.clear(); y.clear();
        fori(0,n)
        {
            cin>>a>>b;
            x.insert(a);
            y.insert(b);
        }
        cout<<(X-x.size())*(Y-y.size())<<endl;
    }
    return 0;
}