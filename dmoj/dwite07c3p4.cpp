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

pii p[1001];
int n,k,a,b;
vector<int> fen;

int cross(int x0,int y0,int x1,int y1,int x2,int y2)
{
    return (x1-x0)*(y2-y0)-(x2-x0)*(y1-y0);
}
bool cmp(pii xx,pii yy)
{
    return cross(p[0].pf,p[0].ps,xx.pf,xx.ps,yy.pf,yy.ps)>0;
}
int dist(pii xx,pii yy)
{
    return ceil(sqrt((xx.pf-yy.pf)*(xx.pf-yy.pf)+(xx.ps-yy.ps)*(xx.ps-yy.ps)));
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    forj(0,5)
    {
        cin>>n>>k; a=0; fen.clear();
        fori(0,n)
            cin>>p[i].pf>>p[i].ps;
        fori(0,n)
            if(p[i].pf<p[a].pf)
                a=i;
        swap(p[a],p[0]);
        sort(p+1,p+n,cmp);
        fen.push_back(0);
        fori(1,n)
        {
            while(fen.size()>1&&cross(p[fen[fen.size()-1]].pf,p[fen[fen.size()-1]].ps,p[i].pf,p[i].ps,p[fen[fen.size()-2]].pf,p[fen[fen.size()-2]].ps)<0)
                fen.pop_back();
            fen.push_back(i);
        }
        a=0;
        fori(0,fen.size())
        {
            a+=dist(p[fen[i]],p[fen[(i+1)%fen.size()]]);
        }
        cout<<"$"<<a*k<<".00\n";
    }
    return 0;
}