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

int x,y,x1,Y1,d,xx,yy;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    cin>>x>>y>>x1>>Y1>>d;
    d-=abs(x-x1)+abs(y-Y1);
    if(d<0||d%2)
    {
        cout<<"impossible\n";
        return 0;
    }
    if(d==0)
    {
        cout<<0<<"\n";
        return 0;
    }
    xx=yy=1;
    if(x1<x)
        xx=-1;
    if(Y1<y)
        yy=-1;
    if(abs(x-x1)>1)
    {
        d-=2;
        cout<<max(y,Y1)-min(y,Y1)+1+d<<"\n";
        fori(min(y,Y1),max(y,Y1)+1)
            cout<<min(x,x1)+1<<" "<<i<<"\n";
        fori(0,d/2)
        {
            cout<<min(x,x1)+1<<" "<<min(y,Y1)-i-1<<"\n";
            cout<<min(x,x1)+1<<" "<<max(y,Y1)+i+1<<"\n";
        }
    }
    else if(abs(y-Y1)>1)
    {
        d-=2;
        cout<<max(x,x1)-min(x,x1)+1+d<<"\n";
        fori(min(x,x1),max(x,x1)+1)
            cout<<i<<" "<<min(y,Y1)+1<<"\n";
        fori(0,d/2)
        {
            cout<<min(x,x1)-i-1<<" "<<min(y,Y1)+1<<"\n";
            cout<<max(x,x1)+i+1<<" "<<min(y,Y1)+1<<"\n";
        }
    }
    else if(abs(x-x1)==1&&abs(y-Y1)==1)
    {
        if(d==2)
        {
            cout<<"impossible\n";
            return 0;
        }
        d-=2;
        cout<<d<<"\n";
        fori(1,d/2+1)
        {
            cout<<x<<" "<<y+yy*i<<"\n";
            cout<<x1<<" "<<Y1-yy*i<<"\n";
        }
    }
    else
        cout<<"impossible\n";
    return 0;
}