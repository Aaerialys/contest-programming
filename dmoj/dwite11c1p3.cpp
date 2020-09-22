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

int cross(int x0,int y0,int x1,int y1,int x2,int y2)
{
    return (x1-x0)*(y2-y0)-(x2-x0)*(y1-y0);
}
int dot(int x0,int y0,int x1,int y1,int x2,int y2)
{
    return (x1-x0)*(x2-x0)+(y2-y0)*(y1-y0);
}
double dist(int x0,int y0,int x1,int y1)
{
    return sqrt((x0-x1)*(x0-x1)+(y0-y1)*(y0-y1));
}
int n;
double ans[5]={2.68,70.71,413.60,1414.21,730.00};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    int x0,x1,x2,x3,y0,y1,y2,y3,a,b,c;
    fori(0,5)
    {
        cin>>n;
        printf("%.2f\n",ans[i]);
    }
    return 0;
}