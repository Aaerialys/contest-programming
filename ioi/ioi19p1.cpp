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

const int N=200200,M=100100;
class biTree
{
    public:
    ll tree[N];
    void add(int x,int v)
    {
        while(x<N)
        {
            tree[x]+=v;
            x+=(x&(-x));
        }
    }
    ll addto(int x)
    {
        ll sum=0;
        while(x>0)
        {
            sum+=tree[x];
            x-=(x&(-x));
        }
        return sum;
    }
};
biTree bit;
queue<int> fr[N];
ll n,cnt=1,ord[N],t;

ll count_swaps(vector<int> S)
{
    n=S.size();
    fori(0,n)
        fr[S[i]+M].push(i);
    fori(0,n)
        if(!ord[i])
        {
            if(S[i]<0)
            {
                ord[i]=cnt++;
                ord[fr[M-S[i]].front()]=cnt++;
            }
            else
            {
                ord[fr[M-S[i]].front()]=cnt++;
                ord[i]=cnt++;
            }
            fr[M-S[i]].pop();
            fr[M+S[i]].pop();
        }
    fori(0,n)
    {
        t+=bit.addto(N-1)-bit.addto(ord[i]);
        bit.add(ord[i],1);
    }
    return t;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("3-20.in", "r", stdin);
    cin>>n; n*=2; int x;
    vector<int> S;
    fori(0,n)
    {
        cin>>x;
        S.push_back(x);
    }
    cout<<count_swaps(S);
    return 0;
}