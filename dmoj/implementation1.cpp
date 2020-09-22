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

const int N=1000100,L=20;
int n,a[N],a1[N],a2[N],st1[L][N],st2[L][N],ans;

int max1(int l,int r)
{
    int z=log2(r-l+1);
    return max(st1[z][l],st1[z][r-(1<<z)]);
}
int max2(int l,int r)
{
    int z=log2(r-l+1);
    int temp=max(st2[z][l],st2[z][r-(1<<z)]);
    return temp;
}
int min1(int l,int r)
{
    int z=log2(r-l+1);
    return min(st1[z][l],st1[z][r-(1<<z)]);
}
int min2(int l,int r)
{
    int z=log2(r-l+1);
    return min(st2[z][l],st2[z][r-(1<<z)]);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    cin>>n;
    fori(0,n)
    {
        cin>>a[i];
        a2[i]=a[i]+i;
        a1[i]=a[i]-i;
        st1[0][i]=a1[i];
        st2[0][i]=a2[i];
    }
    fori(1,L)
        forj(0,n-(1<<i)+1)
                st1[i][j]=max(st1[i-1][j],st1[i-1][j+(1<<(i-1))]);
    fori(1,L)
        forj(0,n-(1<<i)+1)
                st2[i][j]=max(st2[i-1][j],st2[i-1][j+(1<<(i-1))]);
    fori(0,n)
    {
        ans=max(ans,max2(i,n-1)-i-a[i]);
        ans=max(ans,max1(0,i)+i-a[i]);
    }
    fori(1,L)
        forj(0,n-(1<<i)+1)
                st1[i][j]=min(st1[i-1][j],st1[i-1][j+(1<<(i-1))]);
    fori(1,L)
        forj(0,n-(1<<i)+1)
                st2[i][j]=min(st2[i-1][j],st2[i-1][j+(1<<(i-1))]);
    fori(0,n)
    {
        ans=max(ans,a[i]-(min2(i,n-1)-i));
        ans=max(ans,a[i]-(min1(0,i)+i));
    }
    cout<<ans;
    return 0;
}