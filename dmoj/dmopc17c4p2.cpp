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

const int N=1001;
int n,q,val[N],par[N],a,b,c;
vector<int> gr[N],path;

void dfs(int v,int p)
{
    par[v]=p;
    for(auto i:gr[v])
        if(i!=p)
            dfs(i,v);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    cin>>n>>q;
    fori(0,n)
        cin>>val[i];
    fori(1,n)
    {
        cin>>a>>b; a--; b--;
        gr[a].push_back(b); gr[b].push_back(a);
    }
    forj(0,q)
    {
        cin>>a>>b>>c; b--; c--; path.clear();
        dfs(b,-1);
        while(c!=-1)
        {
            path.push_back(val[c]);
            c=par[c];
        }
        sort(path.begin(),path.end());
        if(a==1)
        {
            b=0;
            fori(0,path.size())
                b+=path[i];
            cout<<round(1.0*b/path.size())<<"\n";
        }
        if(a==2)
            cout<<round((path[(path.size()-1)/2]+path[path.size()/2])/2.0)<<"\n";
        if(a==3)
        {
            b=c=0;
            fori(1,path.size()+1)
                if(i==path.size()||path[i]!=path[i-1])
                {
                    if(c<i-b)
                    {
                        a=path[i-1];
                        c=i-b;
                    }
                    b=i;
                }
            cout<<a<<"\n";
        }
    }
    return 0;
}