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

const int N=1000010;
struct line
{
    int x,y1,y2;
    bool t;
};
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
bool cmp(line xx,line yy)
{
    if(xx.x==yy.x)
        return xx.t<yy.t;
    return xx.x<yy.x;
}
int n,x,a,b,c,d;
ll t;
vector<line> rect;
priority_queue<pii> last;
biTree top,bot;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    cin>>n;
    fori(0,n)
    {
        cin>>a>>b>>c>>d;
        rect.push_back({a,b,d,1});
        rect.push_back({c,b,d,0});
    }
    sort(rect.begin(),rect.end(),cmp);
    for(auto i:rect)
    {
        if(i.t)
        {
            top.add(i.y2,1);
            bot.add(i.y1,1);
        }
        else
        {
            t+=bot.addto(i.y2-1)-top.addto(i.y1);
            top.add(i.y2,-1);
            bot.add(i.y1,-1);
        }
    }
    cout<<t-n;
    return 0;
}
/**
sweep line
find all rectangles with overlap
sort by right and then height, keep when right>current left
overlap+=total-top<=cur bottom -bottom>=cur top
subtract all contained rectangle
sort, keep when left<cur left
contain+=total-top>curtop-bot<curbot

wtf bruce:
lol nope just do top and bottom lines intersect with vertical lines lol bruce big brain me dummy dumb
3
1 1 4 4
3 3 5 5
3 3 5 5
*/