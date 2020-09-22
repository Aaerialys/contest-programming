#include <iostream>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int x1,x2,y1,y2,n,m,xa,xb,ya,yb,t,xx,yy,a;
bool b;
int x(int ax,int bx,int cx,int ay,int by,int cy)
{
    a=(bx-ax)*(cy-ay)-(cx-ax)*(by-ay);
    if(a==0)
        return -1;
    return (bx-ax)*(cy-ay)>(cx-ax)*(by-ay);
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>x1>>y1>>x2>>y2>>n;
    fori(0,n)
    {
        b=false;
        cin>>m>>xx>>yy; xb=xx; yb=yy;
        forj(1,m)
        {
            cin>>xa>>ya;
            if(max(min(x1,x2),min(xa,xb))<=min(max(x1,x2),max(xa,xb))&&max(min(y1,y2),min(ya,yb))<=min(max(y1,y2),max(ya,yb))&&(x(x1,x2,xa,y1,y2,ya)!=x(x1,x2,xb,y1,y2,yb)||x(x1,x2,xb,y1,y2,yb)==-1)&&(x(xa,xb,x1,ya,yb,y1)!=x(xa,xb,x2,ya,yb,y2)||x(xa,xb,x1,ya,yb,y1)==-1))
                b=true;
            xb=xa; yb=ya;
        }
        xa=xx; ya=yy;
            if(max(min(x1,x2),min(xa,xb))<=min(max(x1,x2),max(xa,xb))&&max(min(y1,y2),min(ya,yb))<=min(max(y1,y2),max(ya,yb))&&(x(x1,x2,xa,y1,y2,ya)!=x(x1,x2,xb,y1,y2,yb)||x(x1,x2,xb,y1,y2,yb)==-1)&&(x(xa,xb,x1,ya,yb,y1)!=x(xa,xb,x2,ya,yb,y2)||x(xa,xb,x1,ya,yb,y1)==-1))
                b=true;
        if(b)
            t++;
    }
    cout<<t;
    return 0;
}