#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;
int chr[1000010];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n,k,x=0,c=0;
    cin>>n>>k;
    fori(0,k)
    {
        cin>>x;
        x--;
        chr[x]=-1;
    }
    fori(0,k+1)
    {
        cin>>x;
        x--;
        if(chr[x]==-1)
            chr[x]=0;
        else
        {
            chr[x]=i+1;
            c++;
        }
    }
    stack<int> kid;
    x=0;
    while(c>1)
    {
        if(chr[x]>0)
        {
            kid.push(chr[x]);
            chr[x]=0;
        }
        if(chr[x]==-1&&kid.empty()==false)
        {
            kid.pop();
            chr[x]=0;
            c--;
        }
        x++;
        if(x>=n)
            x-=n;
    }
    if(kid.size()==1)
        cout<<kid.top()<<endl;
    return 0;
}