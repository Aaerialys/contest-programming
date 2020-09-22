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
int n,m,a,b,c,en[N],ex[N],enn,val[N],chn;
bool pos;
vector<int> gr[N],gr0[N];
unordered_set<int> uni;

void dfs(int v,int p)
{
    if(!pos)
        return;
    chn=max(chn,val[v]);
    if(gr0[v].size()>2)
        pos=false;
    for(auto i:gr0[v])
    {
        if(i==p)
            continue;
        if(i==a&&val[v]==25||v==a&&val[i]==25)
        {
            b=-1;
            continue;
        }
        if(val[i]!=-1)
            pos=false;
        val[i]=val[v]+1;
        dfs(i,v);
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    cin>>n>>m; seto(en,-1); seto(val,-1);
    fori(0,n)
        gr[i].push_back(i);
    fori(0,m)
    {
        cin>>a>>b; a--; b--;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    fori(0,n)
        sort(gr[i].begin(),gr[i].end());
    fori(0,n)
    {
        if(enn>26)
            break;
        forj(0,enn)
        {
            pos=true;
            fork(0,gr[ex[j]].size())
                if(gr[ex[j]][k]!=gr[i][k])
                    pos=false;
            if(pos&&gr[ex[j]].size()==gr[i].size())
                en[i]=j;
        }
        if(en[i]==-1)
        {
            en[i]=enn;
            ex[enn++]=i;
        }
    }
    fori(0,enn)
    {
        for(auto j:gr[ex[i]])
            if(en[j]!=i)
                uni.insert(en[j]);
        for(auto j:uni)
            gr0[i].push_back(j);
        uni.clear();
    }
    pos=true; a=-1;
    if(enn==26)
    {
        a=val[0]=0;
        dfs(0,-1);
        if(b!=-1)
            pos=false;
    }
    else
    {
        fori(0,enn)
            if(gr0[i].size()<=1&&val[i]==-1)
            {
                val[i]=chn;
                dfs(i,-1); chn+=2;
            }
    }
    fori(0,enn)
        if(val[i]==-1||val[i]>25||val[i]==25&&enn<26)
            pos=false;
    if(pos)
        fori(0,n)
            cout<<(char)(val[en[i]]+'a');
    else
        cout<<-1;
    return 0;
}