#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

int n,h,d,eh,ed,x,y;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>h>>d;
    fori(0,n)
    {
        cin>>eh>>ed;
        x=ceil(1.0*eh/d); y=ceil(1.0*h/ed);
        //cout<<x<<" "<<(y-1)/3*4+(y-1)%3+1<<endl; continue;
        if(x>(y-1)/3*4+(y-1)%3+1)
            cout<<"Lose "<<(y-1)/3*4+(y-1)%3+1<<"\n";
        else
            cout<<"Win "<<x<<"\n";
    }
    return 0;
}