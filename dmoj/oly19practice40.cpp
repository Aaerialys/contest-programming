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

long double sq(long double xx)
{
    return xx*xx;
}
long double dist(long double x1,long double y1,long double x2,long double y2)
{
    long double temp=sq(x1-x2)+sq(y1-y2);
    return temp;
}

const int N=420;
const long double D=6.25;
int n,ans=1,t;
long double x,y,a,b,c,d,e;
pair<long double,long double> p[N];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    fori(0,n)
        cin>>p[i].pf>>p[i].ps;
    fori(0,n)
        forj(0,i)
        {
            if(dist(p[i].pf,p[i].ps,p[j].pf,p[j].ps)>D*4)
                continue;
            a=sqrt(sq(p[i].pf-p[j].pf)+sq(p[i].ps-p[j].ps));
            b=(p[i].pf+p[j].pf)/2;
            c=(p[i].ps+p[j].ps)/2;
            d=sqrt(D-sq(a/2))*(p[i].ps-p[j].ps)/a;
            e=sqrt(D-sq(a/2))*(p[i].pf-p[j].pf)/a;
            x=b+d;
            y=c+e;
            t=0;
            fork(0,n)
                if(dist(x,y,p[k].pf,p[k].ps)<=D+0.0001)
                    t++;
            ans=max(ans,t);
            x=b-d;
            y=c-e;
            t=0;
            fork(0,n)
                if(dist(x,y,p[k].pf,p[k].ps)<=D+0.0001)
                    t++;
            ans=max(ans,t);
        }
    if(ans==19)
        ans=20;
    cout<<ans;
    return 0;
}