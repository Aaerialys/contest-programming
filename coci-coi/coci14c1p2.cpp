#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n,minx=INT_MAX,miny=INT_MAX,maxx=0,maxy=0,x,y;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        if(minx>x)
            minx=x;
        if(miny>y)
            miny=y;
        if(maxx<x)
            maxx=x;
        if(maxy<y)
            maxy=y;
    }
    if(pow(maxx-minx,2)>pow(maxy-miny,2))
        cout<<pow(maxx-minx,2);
    else
        cout<<pow(maxy-miny,2);
    return 0;
}