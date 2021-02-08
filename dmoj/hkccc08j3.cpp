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

const int N=10010;
int n,m,x;
unordered_map<int,string> name;
unordered_map<int,int> f;
string s;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    cin>>n;
    fori(0,n)
    {
        cin>>s>>x;
        name[x]=s; f[x]=0;
    }
    cin>>m;
    fori(0,m)
    {
        cin>>x;
        f[x]++;
    }
    for(auto i:f)
        if(i.ps>f[x]||i.ps==f[x]&&i.pf<x)
            x=i.pf;
    cout<<name[x];
    return 0;
}