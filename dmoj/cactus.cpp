#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

long long x,y,a[5],b[5],c,d,e,m=0;
double h,f[200100],s;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>h>>y>>x;
    fori(0,x)
    {
        cin>>b[i]>>a[i];
        assert(a[i]<=100);
    }
    fori(0,y)
    {
        cin>>c>>d>>e;
        f[c]+=e;
        f[c+d]-=e;
        m=max(m,c+d);
    }
    fori(1,m)
        f[i]+=f[i-1];
    fori(0,m)
    {
        s=f[i];
        forj(0,x)
            s=min(s,max(0.0,f[i]-b[j])*(100-a[j])/100);
        h-=s;
    }
    if(h<=0)
        cout<<"Act Like A Cactus.";
    else
        printf("%.2f",h);
    return 0;
}