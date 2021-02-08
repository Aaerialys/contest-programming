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

const int N=2010;
int bsum[N][N],wsum[N][N],n,m,t,sz,a,b,c,l,r,mid;
char ch,f[N][N];
string line;

int bsun(int x1,int y1,int x2,int y2)
{
    if(x1<2||y1<2||x2>n||y2>m||x1>x2||y1>y2)
        return -inf;
    return bsum[x2][y2]-bsum[x2][y1-1]-bsum[x1-1][y2]+bsum[x1-1][y1-1];
}
int wsun(int x1,int y1,int x2,int y2)
{
    if(x1<2||y1<2||x2>n||y2>m||x1>x2||y1>y2)
        return -inf;
    return wsum[x2][y2]-wsum[x2][y1-1]-wsum[x1-1][y2]+wsum[x1-1][y1-1];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    cin>>n; m=2*n;
    fori(1,n+1)
    {
        forj(1,m+1)
        {
            cin>>ch; f[i][j]=ch;
            if(ch=='#')
                bsum[i][j]=1;
            if(ch=='.')
                wsum[i][j]=1;
        }
    }
    fori(1,n+1)
        forj(1,m+1)
        {
            bsum[i][j]+=bsum[i][j-1];
            wsum[i][j]+=wsum[i][j-1];
        }
    fori(1,n+1)
        forj(1,m+1)
        {
            bsum[i][j]+=bsum[i-1][j];
            wsum[i][j]+=wsum[i-1][j];
        }
    fori(2,n)
        forj(2,m)
            if(f[i][j]=='#')
            {
                l=j; r=m-1;
                while(l<r)
                {
                    mid=(l+r)/2;
                    if(bsun(i,j,i,mid)==mid-j+1)
                    {
                        sz=mid-j+1;
                        l=mid+1;
                    }
                    else
                        r=mid;
                }
                sz=(sz-3)/2;
                if(sz<=0)
                    continue;
                a=1+(2*sz+2)/3; b=2*sz+3; c=sz/5+1;
                if(bsun(i-c,j+sz+1,i-1,j+sz+1)==c)
                    if(bsun(i,j,i+a-1,j+b-1)==a*b)
                        if(wsun(i-c-1,j+sz,i-1,j+sz+2)==2*c+3)
                            if(wsun(i-1,j-1,i+a,j+b)==2*(a+b)+4-1)
                                t++;
            }
    cout<<t<<"\n";
    return 0;
}
/**

12
########################
#......................#
#.......#..............#
#.......#..............#
#.#############........#
#.#############........#
#.#############.....#..#
#.#############...######
#.#############...######
#......................#
#.....................##
########################

*/