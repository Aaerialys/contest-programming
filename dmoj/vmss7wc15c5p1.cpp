#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

string in;
double a,b,c,x,w,s,m;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>in;
    fori(0,4)
    {
        cin>>a>>b>>c;
        w+=c;
        x+=a/b*c;
        if(c>m)
        {
            m=c;
            s=a/b;
        }
    }
    if(in=="trees!")
        x+=(1-s)*m;
    else
        x-=s*m;
    cout<<round(x/w*100);
    return 0;
}