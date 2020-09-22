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

const int N=300100;

class biTree
{
    public:
    int tree[N]={0};
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

biTree bit[21];
int n,q,a,b,c,d,arr[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>q;
    fori(1,n+1)
    {
        cin>>a; arr[i]=a;
        bit[a].add(i,1);
    }
    fori(0,q)
    {
        cin>>a;
        if(a==1)
        {
            cin>>b>>c;
            bit[arr[b]].add(b,-1);
            bit[c].add(b,1);
            arr[b]=c;
        }
        if(a==2)
        {
            cin>>b>>c>>d; int x;
            for(x=20;d>0;x--)
                d-=bit[x].addto(c)-bit[x].addto(b-1);
            cout<<x+1<<"\n";
        }
    }
    return 0;
}