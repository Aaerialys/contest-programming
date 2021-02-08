#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int n,sum[520][520],paint[520][520],I[520][520][10],J[520][520][10];
char ch;

int pnt(int x,int y,int L)
{
    if(L==0)
        return 0;
    int a[4],b[4],c[4],d[4],l,s=INT_MAX;
    l=1<<(L-1);
    a[0]=sum[x][y]-sum[x-l][y]-sum[x][y-l]+sum[x-l][y-l];
    a[1]=sum[x-l][y]-sum[x-l*2][y]-sum[x-l][y-l]+sum[x-l*2][y-l];
    a[2]=sum[x][y-l]-sum[x-l][y-l]-sum[x][y-l*2]+sum[x-l][y-l*2];
    a[3]=sum[x-l][y-l]-sum[x-l*2][y-l]-sum[x-l][y-l*2]+sum[x-l*2][y-l*2];
    b[0]=l*l-a[0];
    b[1]=l*l-a[1];
    b[2]=l*l-a[2];
    b[3]=l*l-a[3];
    c[0]=pnt(x,y,L-1);
    c[2]=pnt(x,y-l,L-1);
    c[1]=pnt(x-l,y,L-1);
    c[3]=pnt(x-l,y-l,L-1);
    fori(0,4)
        forj(0,4)
            if(i!=j)
            {
                fork(0,4)
                    d[k]=c[k];
                d[i]=a[i]; d[j]=b[j];
                if(s>d[0]+d[1]+d[2]+d[3])
                {
                    s=d[0]+d[1]+d[2]+d[3];
                    I[x][y][L]=i; J[x][y][L]=j;
                }
            }
    return s;
}
void fll(int x,int y,int L)
{
    if(L==0)
    {
        paint[x][y]=sum[x][y]-sum[x-1][y]-sum[x][y-1]+sum[x-1][y-1];
        return;
    }
    int a,b,c,d,l=1<<(L-1);
    fll(x,y,L-1); fll(x-l,y,L-1); fll(x,y-l,L-1); fll(x-l,y-l,L-1);
    a=x-l; b=x; c=y-l; d=y;
    if(I[x][y][L]==1||I[x][y][L]==3)
    {
        a-=l;
        b-=l;
    }
    if(I[x][y][L]==2||I[x][y][L]==3)
    {
        c-=l;
        d-=l;
    }
    fori(a+1,b+1)
        forj(c+1,d+1)
            paint[i][j]=0;
    a=x-l; b=x; c=y-l; d=y;
    if(J[x][y][L]==1||J[x][y][L]==3)
    {
        a-=l;
        b-=l;
    }
    if(J[x][y][L]==2||J[x][y][L]==3)
    {
        c-=l;
        d-=l;
    }
    fori(a+1,b+1)
        forj(c+1,d+1)
            paint[i][j]=1;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    fori(1,n+1)
        forj(1,n+1)
        {
            cin>>ch;
            sum[i][j]=ch-'0';
        }
    fori(1,n+1)
        forj(1,n+1)
            sum[i][j]+=sum[i][j-1];
    fori(1,n+1)
        forj(1,n+1)
            sum[i][j]+=sum[i-1][j];
    cout<<pnt(n,n,log2(n))<<"\n";
    fll(n,n,log2(n));
    fori(1,n+1)
    {
        forj(1,n+1)
            cout<<paint[i][j];
        cout<<"\n";
    }
    return 0;
}