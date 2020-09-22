#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

const int N=131073,B=316;
int tree[N],sum;

class biTree
{
    public:
    void add(int x,int v)
    {
        while(x<=N)
        {
            tree[x]+=v;
            x+=(x&(-x));
        }
    }
    int addto(int x)
    {
        sum=0;
        while(x>0)
        {
            sum+=tree[x];
            x-=(x&(-x));
        }
        return sum;
    }
};
int64_t hilbertOrder(int x, int y, int pow, int rotate) {
	if(!pow) return 0;
	const int hpow=1<<(pow-1),seg=((x<hpow? (y<hpow? 0: 3): (y<hpow? 1 :2))+rotate)&3,rotateDelta[4] = {3, 0, 0, 1},nx=x&(x^hpow),ny=y&(y^hpow);
	const int64_t subSquareSize=1LL<<(2*pow-2),add = hilbertOrder(nx, ny, pow-1,(rotate+rotateDelta[seg])&3);
	return seg*subSquareSize+(seg==1||seg==2? add : (subSquareSize-add-1));
}
struct query
{
    int l,r,i;
    int64_t ord;
    void calc(){
        ord=hilbertOrder(l,r,20,0);
    }
};
bool cmp(query x,query y)
{
    return x.ord<y.ord;
}

biTree bt;
long long n,q,arr[N],l,r=-1,x,ans[N];
pair<int,int> cord[N];
query que[N];

int main()
{
    scanf("%lld",&n);
    fori(0,n)
    {
        scanf("%d",&cord[i].first);
        cord[i].second=i;
    }
    sort(cord,cord+n);
    fori(0,n)
    {
        if(i>0&&cord[i].first==cord[i-1].first)
            arr[cord[i].second]=arr[cord[i-1].second];
        else
            arr[cord[i].second]=i+1;
    }
    scanf("%lld",&q);
    fori(0,q)
    {
        scanf("%d%d",&que[i].l,&que[i].r);
        que[i].i=i; que[i].l--; que[i].r--; que[i].calc();
    }
    sort(que,que+q,cmp);
    fori(0,q)
    {
        while(r>que[i].r)
        {
            x-=bt.addto(N-1)-bt.addto(arr[r]);
            bt.add(arr[r],-1);
            r--;
        }
        while(l<que[i].l)
        {
            x-=bt.addto(arr[l]-1);
            bt.add(arr[l],-1);
            l++;
        }
        while(r<que[i].r)
        {
            r++;
            x+=bt.addto(N-1)-bt.addto(arr[r]);
            bt.add(arr[r],1);
        }
        while(l>que[i].l)
        {
            l--;
            x+=bt.addto(arr[l]-1);
            bt.add(arr[l],1);
        }
        ans[que[i].i]=x;
    }
    fori(0,q)
        printf("%lld\n",ans[i]);
    return 0;
}