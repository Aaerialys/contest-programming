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

ll pas[40][40],n,k,t;

void go(int len,int K)
{
    int x,y,z;
    if(K==0||len==0)
        return;
    for(x=0;x<len&&K>pas[x][x]*pas[len-x-1][len-x-1];x++)
        K-=pas[x][x]*pas[len-x-1][len-x-1];
    x=len-x;
    cout<<'R';
    go(x-1,(K-1)/(pas[len-x][len-x])+1);
    cout<<'D';
    go(len-x,(K-1)%(pas[len-x][len-x])+1);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    fori(0,20)
        pas[0][i]=1;
    fori(1,20)
        forj(i,20)
            pas[i][j]=pas[i-1][j]+pas[i][j-1];
    cin>>n>>k;
    if(k>pas[n-1][n-1])
    {
        cout<<"ERROR";
        return 0;
    }
    go(n-1,k);
    return 0;
}