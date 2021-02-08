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
class biTree
{
    public:
    int tree[N];
    void add(int x,int v)
    {
        while(x<N)
        {
            tree[x]+=v;
            x+=(x&(-x));
        }
    }
    int addto(int x)
    {
        int sum=0;
        while(x>0)
        {
            sum+=tree[x];
            x-=(x&(-x));
        }
        return sum;
    }
};
biTree bits[27];
int n,q,arr[N],qt,a,b;
ll x,t;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    cin>>n>>q;
    fori(1,n+1)
    {
        cin>>x; arr[i]=x;
        forj(0,27)
        {
            if(x&1)
                bits[j].add(i,1);
            x>>=1;
        }
    }
    fori(0,q)
    {
        cin>>qt;
        if(qt==1)
        {
            cin>>a>>b; x=arr[a]; arr[a]=b;
            forj(0,27)
            {
                if(x&1)
                    bits[j].add(a,-1);
                if(b&1)
                    bits[j].add(a,1);
                b>>=1; x>>=1;
            }
        }
        if(qt==2)
        {
            cin>>a>>b; t=0;
            forj(0,27)
            {
                x=bits[j].addto(b)-bits[j].addto(a-1);
                x=x*(b-a)-x*(x-1)/2;
                t+=x*(1<<j);
            }
            cout<<t<<"\n";
        }
        if(qt==3)
        {
            cin>>a>>b; t=0;
            forj(0,27)
            {
                x=bits[j].addto(b)-bits[j].addto(a-1);
                x=x*(x-1)/2;
                t+=x*(1<<j);
            }
            cout<<t<<"\n";
        }
        if(qt==4)
        {
            cin>>a>>b; t=0;
            forj(0,27)
            {
                x=bits[j].addto(b)-bits[j].addto(a-1);
                x=x*(b-a)-x*(x-1);
                t+=x*(1<<j);
            }
            cout<<t<<"\n";
        }
    }
    return 0;
}