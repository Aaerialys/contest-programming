#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

struct cls
{
    int l,r,t,i;
};
bool cmp(cls a,cls b)
{
    if(a.r==b.r)
        return a.l<b.l;
    return a.r<b.r;
}

const int N=10010,B=101;
int n,q,s[N],v[N],x,y,z,l,r,up[N][B],down[N][B],ans[N*10];
long long t;
vector<cls> big,smol;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("in7.txt", "r", stdin);
    //freopen("out7.txt", "w", stdout);
    cin>>n;
    fori(0,n)
    {
        cin>>s[i]>>v[i];
    }
    cin>>q; //q=2585;
    fori(0,q)
    {
        cin>>x>>y>>z; x--; y--;
        //if(i<2580) continue;
        if(y-x>=B)
            big.push_back({x,y,z,i});
        else
            smol.push_back({x,y,z,i});
    }
    sort(smol.begin(),smol.end(),cmp); sort(big.begin(),big.end(),cmp);
    l=r=-1;
    for(auto i:big)
    {
        if(i.l>r)
        {
            forj(0,B)
                up[i.r][j]=down[i.r+1][j]=0;
            forj(i.r+1,n)
                fork(1,B)
                {
                    up[j][k]=max(up[j][k-1],up[j-1][k]);
                    if(k>=s[j])
                        up[j][k]=max(up[j][k],up[j-1][k-s[j]]+v[j]);
                }
            ford(j,i.r,0)
                fork(1,B)
                {
                    down[j][k]=max(down[j][k-1],down[j+1][k]);
                    if(k>=s[j])
                        down[j][k]=max(down[j][k],down[j+1][k-s[j]]+v[j]);
                }
            r=i.r;
        }
        x=0;
        forj(0,i.t+1)
        {
            x=max(x,down[i.l][j]+up[i.r][i.t-j]);
        }
        ans[i.i]=x;
        t+=x;
    }
    l=r=-1;
    for(auto i:smol)
    {
        if(i.l>r)
        {
            forj(0,B)
                up[i.r][j]=down[i.r+1][j]=0;
            forj(i.r+1,min(n,i.r+B))
                fork(1,B)
                {
                    up[j][k]=max(up[j][k-1],up[j-1][k]);
                    if(k>=s[j])
                        up[j][k]=max(up[j][k],up[j-1][k-s[j]]+v[j]);
                }
            ford(j,i.r,max(0,i.r-B))
                fork(1,B)
                {
                    down[j][k]=max(down[j][k-1],down[j+1][k]);
                    if(k>=s[j])
                        down[j][k]=max(down[j][k],down[j+1][k-s[j]]+v[j]);
                }
            r=i.r;
        }
        x=0;
        forj(0,i.t+1)
        {
            x=max(x,down[i.l][j]+up[i.r][i.t-j]);
        }
        ans[i.i]=x;
        t+=x;
    }
    //fori(0,q)
      //  cout<<ans[i]<<"\n";
    cout<<t<<endl;
    return 0;
}
/**
331542571
332200013
*/