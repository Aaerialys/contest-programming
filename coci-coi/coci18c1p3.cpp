#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define seto(x,i) memset(x,i,sizeof x)
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define pf first
#define ps second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int N=100010;
int n,m,ls[N],rs[N],l,r,mid,ans;

bool pos(int x)
{
    int j=0;
    fori(0,n)
    {
        for(;j<m&&abs(ls[i]-rs[j])>x;j++);
        if(j==m)
            return false;
        j++;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    cin>>n>>m;
    fori(0,n)
        cin>>ls[i];
    fori(0,m)
        cin>>rs[i];
    if(n>m)
    {
        swap(n,m);
        swap(ls,rs);
    }
    sort(ls,ls+n); sort(rs,rs+m);
    r=inf;
    while(l<r)
    {
        mid=(l+r)/2;
        if(pos(mid))
            r=mid;
        else
            l=mid+1;
    }
    cout<<r<<"\n";
    return 0;
}