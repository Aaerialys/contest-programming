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

const int N=12;
int n,x0,yy0,mc,md[101];

void dfs(int x,int y,char st[N][N],int dist,int candy)
{
    char st2[N][N];
    fori(0,N)
        forj(0,N)
            st2[i][j]=st[i][j];
    if(st2[x][y]=='*')
    {
        candy++; mc=max(mc,candy);
        md[candy]=min(md[candy],dist);
        fori(1,n+1)
            forj(1,n+1)
            {
                if(st2[i][j]=='a'&&candy>=1)
                    st2[i][j]='.';
                if(st2[i][j]=='b'&&candy>=2)
                    st2[i][j]='.';
                if(st2[i][j]=='c'&&candy>=3)
                    st2[i][j]='.';
                if(st2[i][j]=='d'&&candy>=4)
                    st2[i][j]='.';
                if(st2[i][j]=='e'&&candy>=5)
                    st2[i][j]='.';
                if(st2[i][j]=='f'&&candy>=6)
                    st2[i][j]='.';
                if(st2[i][j]=='B')
                    st2[i][j]='.';
            }
    }
    st2[x][y]='B';
    if(st2[x-1][y]=='.'||st2[x-1][y]=='*')
        dfs(x-1,y,st2,dist+1,candy);
    if(st2[x+1][y]=='.'||st2[x+1][y]=='*')
        dfs(x+1,y,st2,dist+1,candy);
    if(st2[x][y-1]=='.'||st2[x][y-1]=='*')
        dfs(x,y-1,st2,dist+1,candy);
    if(st2[x][y+1]=='.'||st2[x][y+1]=='*')
        dfs(x,y+1,st2,dist+1,candy);
}

int main()
{
    //ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    fork(0,5)
    {
        char st[N][N]; seto(st,'#'); seto(md,inf); mc=0; md[0]=0;
        cin>>n;
        fori(1,n+1)
            forj(1,n+1)
            {
                cin>>st[i][j];
                if(st[i][j]=='B')
                {
                    x0=i; yy0=j;
                    st[i][j]='.';
                }
            }
        dfs(x0,yy0,st,0,0);
        cout<<mc<<" "<<md[mc]<<"\n";
    }
    return 0;
}