#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

int n,q,t,p[100100],e[100100],f[100100],fail[100100];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    fori(0,n)
        cin>>e[i]>>f[i]>>p[i];
    cin>>q;
    fori(0,q)
    {
        cin>>fail[i];
    }
    sort(fail,fail+q);
    fori(0,n)
        if(lower_bound(fail,fail+q,e[i])==upper_bound(fail,fail+q,f[i]))
            t+=p[i];
    cout<<t;
    return 0;
}