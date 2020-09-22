#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

bool sum[20][180][4];
long long x,y,t;
vector<int>l,r;

void pos(int a,int b,int c)
{
    if(sum[a][b][c])
        return;
    sum[a][b][c]=true;
    if(a==r.size()-1)
        return;
    int x=0,y=9;
    a++;
    if(c==0)
    {
        pos(a,b+l[a],c);
        x=l[a]+1;
    }
    if(c==2)
    {
        pos(a,b+r[a],c);
        y=r[a]-1;
    }
    if(c==3)
    {
        x=l[a]+1;
        y=r[a]-1;
        if(l[a]==r[a])
            pos(a,b+l[a],3);
        else
        {
            pos(a,b+l[a],0);
            pos(a,b+r[a],2);
        }
    }
    fori(x,y+1)
    {
        pos(a,b+i,1);
    }
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>x>>y;
    while(y>0)
    {
        l.push_back(x%10); r.push_back(y%10);
        x/=10; y/=10;
    }
    l.push_back(0); r.push_back(0);
    reverse(r.begin(),r.end()); reverse(l.begin(),l.end());
    pos(0,0,3);
    fori(0,180)
    {
        if(sum[r.size()-1][i][0]||sum[r.size()-1][i][1]||sum[r.size()-1][i][2]||sum[r.size()-1][i][3])
            t++;
    }
    cout<<t<<endl;
    return 0;
}