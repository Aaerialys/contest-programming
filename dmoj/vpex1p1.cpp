#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

int s1,m1=101,s2,m2=101,x;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("in7.txt", "r", stdin);
    //freopen("out7.txt", "w", stdout);
    fori(0,5)
    {
        cin>>x; assert(1<=x&&x<=100);
        s1+=x;
        m1=min(m1,x);
    }
    fori(0,5)
    {
        cin>>x; assert(1<=x&&x<=100);
        s2+=x;
        m2=min(m2,x);
    }
    cout<<max(s1-m1,s2-m2);
    return 0;
}