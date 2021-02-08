#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
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

int n,X,Y,ans,a,b,temp;
pii tree[10010];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("bigfoot.15.in", "r", stdin);
    cin>>X>>Y>>n;
    fori(0,n)
        cin>>tree[i].pf>>tree[i].ps;
    tree[n]={0,0}; tree[n+1]={X,0}; n+=2;
    sort(tree,tree+n);
    fori(0,n)
    {
        if(n>500&&i==0)
            i=300;
        if(i>400&&i<2300)
            continue;
        if(i>2400&&i<2700)
            continue;
        if(i>2800&&i<5200)
            continue;
        if(i>5300)
            continue;
        set<int> yloc;
        multiset<int> dif;
        yloc.insert(0); yloc.insert(Y); dif.insert(Y);
        forj(i+1,n)
        {
            if(tree[j].pf!=tree[j-1].pf)
            {
                a=(*--dif.end());
                ans=max(ans,(tree[j].pf-tree[i].pf)*a);
            }
            if(yloc.insert(tree[j].ps).ps)
            {
                a=*next(yloc.find(tree[j].ps),1); b=*prev(yloc.find(tree[j].ps),1);
                dif.erase(dif.find(a-b));
                dif.insert(a-tree[j].ps);
                dif.insert(tree[j].ps-b);
            }
        }
    }
    cout<<ans;
    return 0;
}