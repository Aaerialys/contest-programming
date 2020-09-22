#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

int n,m,lm[1001],rm[1001],x,t,h;
char ch;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    ford(i,n-1,0)
    {
        lm[i]=rm[i]=INT_MAX;
        forj(0,m)
        {
            cin>>ch;
            if(ch=='J'&&lm[i]==INT_MAX)
                lm[i]=j;
            if(ch=='J')
                rm[i]=j;
        }
    }
    lm[n]=rm[n]=INT_MAX;
    if(rm[0]==INT_MAX)
        rm[0]=0;
    fori(1,n+1)
    {
        if(rm[i]!=INT_MAX)
            h=i;
        if(i%2)
        {
            if(rm[i]==INT_MAX)
                rm[i]=x;
            if(rm[i-1]==INT_MAX)
                rm[i-1]=x;
            t+=max(rm[i],rm[i-1])-x;
            x=max(rm[i],rm[i-1]);
        }
        else
        {
            if(lm[i]==INT_MAX)
                lm[i]=x;
            if(lm[i-1]==INT_MAX)
                lm[i-1]=x;
            t+=x-min(lm[i],lm[i-1]);
            x=min(lm[i],lm[i-1]);
        }
    }
    cout<<t+h;
    return 0;
}