#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

const int N=100002, LOG=18;
int n,e,q,a,b,c,d,t,lca[LOG][N], dfn[N], low[N], dfr[N], dep[N], cnt, fa, son;
vector<int> gr[N];

void dfs(int v,int p)
{
    dfn[v]=low[v]=++cnt;
    for(auto i:gr[v])
    {
        if(i==p) continue;
        if(!dfn[i])
        {
            dep[i]=dep[v]+1; lca[0][i]=v;
            dfs(i,v);
            low[v]=min(low[v],low[i]);
        }
        else
            low[v]=min(low[v],dfn[i]);
    }
    dfr[v]=++cnt;
}
bool isPar(int x, int y)
{
    return dfn[x] <= dfn[y] && dfr[x] >= dfr[y];
}
int upNLCA(int u, int d){
    int pos = 0, anc = u;
    for(int i=LOG-1; i>=0; i--){
        pos += (1<<i);
        if(pos > d) pos -= (1<<i);
        else anc = lca[i][anc];
    }
    return anc;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(lca, -1, sizeof(lca));
    cin>>n>>e;
    fori(0,e)
    {
        cin>>a>>b;
        gr[a].push_back(b); gr[b].push_back(a);
    }
    cin>>q;
    dfs(1,0);
    fori(1,LOG)
        forj(1,n+1)
            lca[i][j]=lca[i-1][lca[i-1][j]];
    fori(0,q){
        cin>>t>>a>>b>>c;
        if(t==1)
        {
            cin>>d;
            if(isPar(d, c))
                swap(c,d);
            if(low[d] <= dfn[c])
                cout<<"yes\n";
            else if((isPar(d,a)&&isPar(d,b))||(!isPar(d,a)&&!isPar(d,b)))
                cout<<"yes\n";
            else
                cout<<"no\n";
        }
        if(t==2)
        {
            //cout << dfn[a] << "  " << dfr[a] << " " << dfn[b] << " " << dfr[b] << " " << dfn[c] << " " << dfr[c] << endl;
            if(!isPar(c, a) && !isPar(c, b)) cout<<"yes\n";
            else if(!isPar(c, a) && isPar(c, b)){
                int t = upNLCA(b, dep[b] - dep[c] - 1);
                if(low[t] < dfn[c])
                    cout<<"yes\n";
                else
                    cout<<"no\n";
            }else if(isPar(c, a) && !isPar(c, b)){
                int t = upNLCA(a, dep[a] - dep[c] - 1);
                if(low[t] < dfn[c])
                    cout<<"yes\n";
                else
                    cout<<"no\n";
            }else{
                int ta = upNLCA(a, dep[a]-dep[c]-1), tb = upNLCA(b, dep[b] - dep[c] - 1);
                if ( (low[ta] < dfn[c] && low[tb]<dfn[c]) || ta==tb) cout<<"yes\n";
                else cout<<"no\n";
            }
        }
    }
    return 0;
}