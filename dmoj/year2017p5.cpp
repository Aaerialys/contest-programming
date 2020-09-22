#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int l,r,n,k,x,y,m;
char ch;
vector<int> blue,red,bs,rs;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    blue.push_back(0); bs.push_back(0); red.push_back(0); rs.push_back(0);
    fori(0,n)
    {
        cin>>ch;
        if(ch=='0')
        {
            red.push_back(i);
            rs.push_back(rs.back()+i);
        }
        if(ch=='1')
        {
            blue.push_back(i);
            bs.push_back(bs.back()+i);
        }
    }
    l=r=1;
    while(r<blue.size())
    {
        x=(l+r)/2;
        y=bs[r]-bs[x]-blue[x]*(r-x)-(r-x)*(r-x+1)/2+blue[x]*(x-l)-bs[x-1]+bs[l-1]-(x-l)*(x-l+1)/2;
        if(y<=k)
        {
            m=max(m,r-l+1);
            r++;
        }
        else
            l++;
    }
    cout<<m<<" ";
    l=r=m=1;
    while(r<red.size())
    {
        x=(l+r)/2;
        y=rs[r]-rs[x]-red[x]*(r-x)-(r-x)*(r-x+1)/2+red[x]*(x-l)-rs[x-1]+rs[l-1]-(x-l)*(x-l+1)/2;
        if(y<=k)
        {
            m=max(m,r-l+1);
            r++;
        }
        else
            l++;
    }
    cout<<m<<endl;
    return 0;
}