#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define seto(x,i) memset(x,i,sizeof x)
#define inf 0x3f3f3f3f;
#define INF 0x3f3f3f3f3f3f3f3f;
#define pf first
#define ps second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

string in;
long long l=1,m,a[50],b[50],p[50],M=1e9+7,B=26,t,s;

int numf(int l,int r)
{
    return (a[r]-a[l-1]*p[r-l+1]%M+M)%M;
}
int numb(int l,int r)
{
    return (b[l]-b[r+1]*p[r-l+1]%M+M)%M;
}
bool pal(int l,int r)
{
    s=numf(l,(l+r)/2);
    t=numb((l+r+1)/2,r);
    return s==t;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    p[0]=1;
    fori(1,50)
        p[i]=p[i-1]*B%M;
    cin>>in;
    fori(0,in.size())
        a[i+1]=(a[i]*B+in[i]-'a'+1)%M;
    ford(i,in.size()-1,0)
        b[i+1]=(b[i+2]*B+in[i]-'a'+1)%M;
    fori(1,in.size()+1)
    {
        while(m<i&&pal(i-m,i))
            m++;
        while(m<i-1&&pal(i-m-1,i))
            m+=2;
    }
    cout<<m;
    return 0;
}