#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int n,x[10],y[10];
double a,b,c,d,m;

double dist(int x1,int y1,int x2,int y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    fori(0,n)
        cin>>x[i]>>y[i];
    if(n==1)
    {
        cout<<0;
        return 0;
    }
    if(n==2)
    {
        cout<<sqrt(dist(x[0],y[0],x[1],y[1]));
        return 0;
    }
    fori(0,n)
        forj(0,i)
            fork(0,j)
            {
                a=dist(x[i],y[i],x[j],y[j]); b=dist(x[i],y[i],x[k],y[k]); c=dist(x[j],y[j],x[k],y[k]); d=max(a,max(b,c));
                if(d*d*2>=a*a+b*b+c*c)
                    m=max(m,d*1.0);
                else
                    m=max(m,2*(a*b*c)/sqrt((a+b+c)*(a+b-c)*(a-b+c)*(-a+b+c)));
            }
    printf("%.2f",m);
    return 0;
}