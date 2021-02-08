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

const int N=18,NN=1<<16;
int n,m,gr[N][N],dist[N][N],a,b,c,car[NN],dp[3][NN],p[N];
bool vis[N];

void dfs(int x)
{
    int v;
    fori(0,n+2)
    {
        v=n+2;
        forj(0,n+2)
            if(dist[x][v]>dist[x][j]&&!vis[j])
                v=j;
        vis[v]=true;
        forj(0,n+2)
            if(dist[x][j]>dist[x][v]+gr[v][j])
                dist[x][j]=dist[x][v]+gr[v][j];
    }
}

int go(int cn,int stu)
{
    if(dp[cn][stu]<inf)
        return dp[cn][stu];
    if(cn==0&&stu==0)
        return dp[cn][stu]=0;
    if(cn==0)
        return dp[cn][stu]=inf-1;
    dp[cn][stu]=inf-1;
    vector<int> st; int aa;
    fori(1,n+1)
        if(stu&p[i])
            st.push_back(i);
    for(auto i:st)
    {
        aa=p[i];
        dp[cn][stu]=min(dp[cn][stu],max(car[aa],go(cn-1,stu^aa)));
        if(car[aa]>=dp[cn][stu])
            continue;
        for(auto j:st)
        {
            if(j<=i)
                continue;
            aa=p[i]+p[j];
            if(car[aa]>=dp[cn][stu])
                continue;
            dp[cn][stu]=min(dp[cn][stu],max(car[aa],go(cn-1,stu^aa)));
            for(auto k:st)
            {
                if(k<=j)
                    continue;
                aa=p[i]+p[j]+p[k];
                if(car[aa]>=dp[cn][stu])
                    continue;
                dp[cn][stu]=min(dp[cn][stu],max(car[aa],go(cn-1,stu^aa)));
                for(auto ii:st)
                {
                    if(ii<=k)
                        continue;
                    aa=p[i]+p[j]+p[k]+p[ii];
                    dp[cn][stu]=min(dp[cn][stu],max(car[aa],go(cn-1,stu^aa)));
                    for(auto jj:st)
                    {
                        if(jj<=ii)
                            continue;
                        aa=p[i]+p[j]+p[k]+p[ii]+p[jj];
                        if(car[aa]>=dp[cn][stu])
                            continue;
                        dp[cn][stu]=min(dp[cn][stu],max(car[aa],go(cn-1,stu^aa)));
                    }
                }
            }
        }
    }
    return dp[cn][stu];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    cin>>n>>m; seto(dist,inf); seto(gr,inf); seto(car,inf); seto(dp,inf); p[0]=1;
    fori(1,N)
        p[i]=p[i-1]<<1;
    fori(0,m)
    {
        cin>>a>>b>>c;
        gr[a][b]=min(gr[a][b],c);
        gr[b][a]=min(gr[b][a],c);
    }
    fori(0,n+2)
    {
        dist[i][i]=0; seto(vis,false);
        dfs(i);
    }
    fori(1,n+1)
    {
        a=p[i];
        car[a]=min(car[a],dist[0][i]+dist[i][n+1]+5);
        forj(1,n+1)
        {
            if(j==i)
                continue;
            a=p[i]+p[j];
            car[a]=min(car[a],dist[0][i]+dist[i][j]+dist[j][n+1]+10);
            fork(1,n+1)
            {
                if(k==i||k==j)
                    continue;
                a=p[i]+p[j]+p[k];
                car[a]=min(car[a],dist[0][i]+dist[i][j]+dist[j][k]+dist[k][n+1]+15);
                ford(ii,n,1)
                {
                    if(ii==i||ii==j||ii==k)
                        continue;
                    a=p[i]+p[j]+p[k]+p[ii];
                    car[a]=min(car[a],dist[0][i]+dist[i][j]+dist[j][k]+dist[k][ii]+dist[ii][n+1]+20);
                    ford(jj,n,1)
                    {
                        if(jj==i||jj==j||jj==k||jj==ii)
                            continue;
                        a=p[i]+p[j]+p[k]+p[ii]+p[jj];
                        car[a]=min(car[a],dist[0][i]+dist[i][j]+dist[j][k]+dist[k][ii]+dist[ii][jj]+dist[jj][n+1]+25);
                    }
                }
            }
        }
    }
    cout<<go(ceil(n/5.0),(p[n+1])-2);
    return 0;
}
/**
7 9
0 2 100
8 2 100
0 3 50
3 4 50
5 6 20
1 6 20
3 6 10
6 7 10
7 8 10

*/