#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

int cross(int x0,int y0,int x1,int y1,int x2,int y2)
{
    return (x1-x0)*(y2-y0)-(x2-x0)*(y1-y0);
}

int x[30],y[30],n,t;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ford(xx,5,1)
    {
        cin>>n; t=0;
        fori(0,n)
            cin>>x[i]>>y[i];
        fori(2,n)
            forj(0,i)
                fork(0,j)
                {
                    if(cross(x[i],y[i],x[j],y[j],x[k],y[k])<0&&cross(x[i],y[i],x[j],y[j],0,0)<0&&cross(x[i],y[i],0,0,x[k],y[k])<0&&cross(0,0,x[j],y[j],x[k],y[k])<0)
                        t++;
                    if(cross(x[i],y[i],x[j],y[j],x[k],y[k])>0&&cross(x[i],y[i],x[j],y[j],0,0)>0&&cross(x[i],y[i],0,0,x[k],y[k])>0&&cross(0,0,x[j],y[j],x[k],y[k])>0)
                        t++;
                }
        cout<<t<<endl;
    }
    return 0;
}