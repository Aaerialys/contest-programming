#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

const int N=10000000;
int a,b,c,d,q,y=N*10,ans[N];

int f(int x)
{
    if(x<=0)
        return 1;
    if(x<N&&ans[x]!=0)
        return ans[x];
    if(x<N)
        return ans[x]=f(x/a-b)+f(x/c-d);
    return f(x/a-b)+f(x/c-d);
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>a>>b>>c>>d>>q;
    fori(0,N)
        f(i);
    fori(0,q)
    {
        cin>>y;
        cout<<f(y)<<"\n";
    }
    return 0;
}