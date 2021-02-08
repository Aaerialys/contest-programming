#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int d,l[3],xx,yy,zz,o[3],dir[3]={1,1,1},p[3]={0,1,2},m=INT_MAX;
char t;

int dist(int x1,int y1,int z1,int x2,int y2,int z2)
{
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2)*1.0;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>l[0]>>l[1]>>l[2]>>xx>>yy>>zz;
    while(t!='E')
    {
        cin>>d>>t;
        o[0]=xx; o[1]=yy; o[2]=zz;
        o[p[0]]=min(o[p[0]],max(l[p[0]],l[p[0]]+d*dir[p[0]]));
        o[p[0]]=max(o[p[0]],min(l[p[0]],l[p[0]]+d*dir[p[0]]));
        o[p[1]]=l[p[1]]; o[p[2]]=l[p[2]];
        m=min(m,dist(o[0],o[1],o[2],xx,yy,zz));
        l[p[0]]+=d*dir[p[0]];
        if(t=='L')
        {
            swap(p[0],p[1]);
            dir[p[1]]*=-1;
        }
        if(t=='R')
        {
            swap(p[0],p[1]);
            dir[p[0]]*=-1;
        }
        if(t=='U')
        {
            swap(p[0],p[2]);
            dir[p[2]]*=-1;
        }
        if(t=='D')
        {
            swap(p[0],p[2]);
            dir[p[0]]*=-1;
        }
    }
    printf("%.2f",sqrt(m));
    return 0;
}