#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

long long n,k,q,x,y,lx,ly,t;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>k>>q;
    fori(0,q)
    {
        cin>>x>>y; t=0;
        if(x>y)
            swap(x,y);
        if(k==1)
        {
            cout<<y-x<<"\n";
            continue;
        }
        lx=ceil(log(x*(k-1)+1)/log(k));
        ly=ceil(log(y*(k-1)+1)/log(k));
        while(ly>lx)
        {
            t++;
            y-=(pow(k,ly-1)-1)/(k-1); y--;
            y/=k; y++; ly--;
            y+=(pow(k,ly-1)-1)/(k-1);
        }
        while(x!=y)
        {
            t+=2;
            x-=(pow(k,lx-1)-1)/(k-1); x--;
            x/=k; x++; lx--;
            x+=(pow(k,lx-1)-1)/(k-1);
            y-=(pow(k,ly-1)-1)/(k-1); y--;
            y/=k; y++; ly--;
            y+=(pow(k,ly-1)-1)/(k-1);

        }
        cout<<t<<"\n";
    }
    return 0;
}