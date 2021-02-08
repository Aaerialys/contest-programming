#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

const int N=100100,B=310;

int64_t hilbertOrder(int x, int y, int pow=20, int rotate=0) {
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
        ord=hilbertOrder(l,r);
    }
};
bool cmp(query x,query y)
{
    return x.ord<y.ord;
}

int n,q,x,l,r=-1,vol[N],ans[N],f[N];
query que[N];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    fori(0,n)
        cin>>vol[i];
    cin>>q;
    fori(0,q)
    {
        cin>>que[i].l>>que[i].r; que[i].l--; que[i].r--;
        que[i].i=i; que[i].calc();
    }
    sort(que,que+q,cmp);
    fori(0,q)
    {
        while(r<que[i].r)
        {
            r++;
            f[vol[r]]++;
            if(f[vol[r]]%2==0)
                x++;
            if(f[vol[r]]%2==1&&f[vol[r]]>1)
                x--;
        }
        while(l>que[i].l)
        {
            l--;
            f[vol[l]]++;
            if(f[vol[l]]%2==0)
                x++;
            if(f[vol[l]]%2==1&&f[vol[l]]>1)
                x--;
        }
        while(r>que[i].r)
        {
            f[vol[r]]--;
            if(f[vol[r]]%2==0&&f[vol[r]]>0)
                x++;
            if(f[vol[r]]%2==1)
                x--;
            r--;
        }
        while(l<que[i].l)
        {
            f[vol[l]]--;
            if(f[vol[l]]%2==0&&f[vol[l]]>0)
                x++;
            if(f[vol[l]]%2==1)
                x--;
            l++;
        }
        ans[que[i].i]=x;
    }
    fori(0,q)
        cout<<ans[i]<<"\n";
    return 0;
}
/*
sort query, divide into block
split into blocks based on l value
sort within blocks based on r value
do the query that way
n*sqrt(n)+q*sqrt(n) time;
:())
*/