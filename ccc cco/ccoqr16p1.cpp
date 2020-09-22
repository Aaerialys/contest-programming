#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;
int a1,a2,a3,a4;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n,a,b,c,d,x;
    unsigned long long t=0;
    cin>>n;
    pair<int,int> px[n],py[n];
    fori(0,n)
    {
        cin>>a>>b;
        px[i].first=a; py[i].second=a; px[i].second=b; py[i].first=b;
    }
    sort(px,px+n); sort(py,py+n);
    fori(0,n)
    {
        x=lower_bound(py,py+n,make_pair(px[i].second,px[i].first))-py;
        a=i-(lower_bound(px,px+n,make_pair(px[i].first,INT_MIN))-px);
        b=lower_bound(px,px+n,make_pair(px[i].first,INT_MAX))-px-1-i;
        c=x-(lower_bound(py,py+n,make_pair(px[i].second,INT_MIN))-py);
        d=lower_bound(py,py+n,make_pair(px[i].second,INT_MAX))-py-1-x;
        if(a<0) 
            a1=1;
        if(b<0)
            a2=1;
        if(c<0)
            a3=1;
        if(d<0)
            a4=1;
        t+=1LL*a*b*c*d;
        if(1LL*a*b*c*d<0)
            cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<a*b*c*d<<endl;
    }
    cout<<t*2<<endl;
    return 0;
}