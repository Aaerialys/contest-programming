#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int n,m,k,q,cx,cy,x[2010],y[2010];
short dif[4001][4001];
map<int,short>rx,ry,rx2,ry2;
vector<long long>xx,yy,xx2,yy2;
long long ans,ans2;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>k;
    n++;m++;
    fori(0,k)
        cin>>x[i]>>y[i];
    cin>>q;
    if(q==0)
    {
        cout<<k;
        return 0;
    }
    fori(0,k)
    {
        rx[x[i]+q+1]=0;
        rx[x[i]-q]=0;
        ry[y[i]+q+1]=0;
        ry[y[i]-q]=0;
    }
    for(auto &it:rx)
    {
        it.second=++cx;
        xx.push_back(max(min(it.first,n),1));
    }
    for(auto &it:ry)
    {
        it.second=++cy;
        yy.push_back(max(min(it.first,m),1));
    }
    fori(0,k)
    {
        dif[rx[x[i]-q]][ry[y[i]-q]]++;
        dif[rx[x[i]+q+1]][ry[y[i]+q+1]]++;
        dif[rx[x[i]+q+1]][ry[y[i]-q]]--;
        dif[rx[x[i]-q]][ry[y[i]+q+1]]--;
    }
    fori(0,cx)
    {
        forj(0,cy)
        {
            dif[i+1][j+1]+=dif[i][j+1]+dif[i+1][j]-dif[i][j];
            if(dif[i+1][j+1]>0)
                ans+=(xx[i+1]-xx[i])*(yy[j+1]-yy[j]);
        }
    }
    fori(0,cx+1)
        forj(0,cy+1)
            dif[i][j]=0;
    cx=cy=0;
    fori(0,k)
    {
        rx2[x[i]+q]=0;
        rx2[x[i]-q+1]=0;
        ry2[y[i]+q]=0;
        ry2[y[i]-q+1]=0;
    }
    for(auto &it:rx2)
    {
        it.second=++cx;
        xx2.push_back(max(min(it.first,n),1));
    }
    for(auto &it:ry2)
    {
        it.second=++cy;
        yy2.push_back(max(min(it.first,m),1));
    }
    fori(0,k)
    {
        dif[rx2[x[i]-q+1]][ry2[y[i]-q+1]]++;
        dif[rx2[x[i]+q]][ry2[y[i]+q]]++;
        dif[rx2[x[i]+q]][ry2[y[i]-q+1]]--;
        dif[rx2[x[i]-q+1]][ry2[y[i]+q]]--;
    }
    fori(0,cx)
    {
        forj(0,cy)
        {
            dif[i+1][j+1]+=dif[i][j+1]+dif[i+1][j]-dif[i][j];
            if(dif[i+1][j+1]>0)
                ans2+=(xx2[i+1]-xx2[i])*(yy2[j+1]-yy2[j]);
        }
    }
    cout<<ans-ans2;
    return 0;
}