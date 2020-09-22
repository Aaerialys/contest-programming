#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(ll i=a;i>=b;i--)
#define seto(x,i) memset(x,i,sizeof x)
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define pf first
#define ps second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
const ll N=4e6,M=300010;
ll n,q,a,b,c,mi,ma,shift,qu[M];
pii que[M];
vector<ll> poi;
unordered_map<ll,int> cord;
class biTree
{
    public:
    ll treev[N];
    int trees[N];
    void ins(ll x,ll v)
    {
        x=cord[x];
        while(x<N)
        {
            treev[x]+=v;
            trees[x]++;
            x+=(x&(-x));
        }
    }
    ll query(ll l,ll r)
    {
        l=cord[l]; r=cord[r];
        return query(r)-query(l-1);
    }
    ll query(int x)
    {
        ll sum=0;
        while(x>0)
        {
            sum+=treev[x];
            x-=(x&(-x));
        }
        return sum;
    }
    int query2(ll l,ll r)
    {
        l=cord[l]; r=cord[r];
        return query2(r)-query2(l-1);
    }
    int query2(int x)
    {
        int sum=0;
        while(x>0)
        {
            sum+=trees[x];
            x-=(x&(-x));
        }
        return sum;
    }
};
biTree tr;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    cin>>n>>q; ma=-INF; mi=INF;
    fori(0,n)
    {
        cin>>qu[i]; a=qu[i];
        poi.push_back(a); ma=max(ma,a); mi=min(mi,a);
    }
    fori(0,q)
    {
        cin>>que[i].pf>>que[i].ps; a=que[i].pf; b=que[i].ps;
        if(a==1)
        {
            poi.push_back(b-shift);
            ma=max(ma,b-shift); mi=min(mi,b-shift);
        }
        if(a==2)
            shift+=b;
        if(a==3)
        {
            ma+=shift; mi+=shift;
            for(ll j=mi-(mi%b+b)%b-shift;j<=ma-shift;j+=b)
            {
                poi.push_back(j); poi.push_back(j+(b-1)/2);
                poi.push_back(j+b-b/2); poi.push_back(j+b-1);
            }
            ma-=shift; mi-=shift;
        }
    }
    sort(poi.begin(),poi.end()); a=0;
    fori(0,poi.size())
    {
        if(a>N)
        {
            cout<<a;
            return 0;
        }
        if(i==0||poi[i]!=poi[i-1])
            cord[poi[i]]=++a;
    }
    ma=-INF; mi=INF; shift=0;
    fori(0,n)
    {
        a=qu[i];
        tr.ins(a,a); ma=max(ma,a); mi=min(mi,a);
    }
    fori(0,q)
    {
        a=que[i].pf; b=que[i].ps;
        if(a==1)
        {
            tr.ins(b-shift,b-shift);
            ma=max(ma,b-shift); mi=min(mi,b-shift);
        }
        if(a==2)
            shift+=b;
        if(a==3)
        {
            c=0; ma+=shift; mi+=shift;
            for(ll j=mi-(mi%b+b)%b-shift;j<=ma-shift;j+=b)
            {
                c+=tr.query(j,j+(b-1)/2)-j*tr.query2(j,j+(b-1)/2);
                c+=(j+b)*tr.query2(j+b-b/2,j+b-1)-tr.query(j+b-b/2,j+b-1);
            }
            ma-=shift; mi-=shift;
            cout<<c<<"\n";
        }
    }
    return 0;
}