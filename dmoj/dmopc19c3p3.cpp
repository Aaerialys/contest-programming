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

const int N=150010;
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
biTree bit;
int n,num[N],x;
ll t;
vector<pii> que;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    cin>>n;
    que.push_back({0,0});
    fori(1,n+1)
    {
        cin>>x; num[i]=num[i-1];
        if(x==1)
            num[i]++;
        else
            num[i]--;
        que.push_back({-num[i],i});
    }
    sort(que.begin(),que.end());
    for(auto i:que)
    {
        t+=bit.addto(N-1)-bit.addto(i.ps);
        if(i.ps!=0)
            bit.add(i.ps,1);
    }
    cout<<t;
    return 0;
}