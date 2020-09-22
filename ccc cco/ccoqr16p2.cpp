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
int n,q,a,b,c,ans[N],first[N],last[N],v,p;
vector<int> gr[N],path;
vector<bool> llen[N];
map<pii,int> ord;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("maze.27.in", "r", stdin);
    cin>>n; seto(first,-1); seto(last,-1);
    fori(0,n)
    {
        cin>>a;
        forj(0,a)
        {
            cin>>b; b--;
            gr[i].push_back(b); ord[(pii){i,b}]=a-j-1;
            llen[i].push_back(false);
        }
        reverse(gr[i].begin(),gr[i].end());
    }
    fori(0,n)
        forj(0,gr[i].size())
        {
            if(llen[i][j])
                continue;
            a=i; b=gr[i][j]; path.clear(); path.push_back(i); v=b; p=i;
            while(true)
            {
                int x=ord[(pii){v,p}];
                x=(x+1)%gr[v].size();
                if(v==a&&gr[v][x]==b)
                    break;
                path.push_back(v);
                llen[v][x]=true;
                p=v; v=gr[v][x];
            }
            fork(0,path.size())
            {
                if(first[path[k]]==-1)
                    first[path[k]]=last[path[k]]=k;
                else
                {
                    ans[path[k]]=max(ans[path[k]],k-last[path[k]]);
                    last[path[k]]=k;
                }
            }
            fork(0,path.size())
                if(first[path[k]]!=-1)
                {
                    ans[path[k]]=max(ans[path[k]],(int)path.size()-last[path[k]]+first[path[k]]);
                    first[path[k]]=last[path[k]]=-1;
                }
        }
    cin>>q;
    forj(0,q)
    {
        cin>>a; a--;
        cout<<ans[a]<<"\n";
        //cout<<j<<" "<<ans<<endl;
    }
    //cout<<cnt<<" "<<m<<endl;
    return 0;
}