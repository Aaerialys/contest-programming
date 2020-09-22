#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;
int kk[100010];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n,k,r,c,t=0,x,y;
    cin>>n>>k>>r;
    fori(0,k)
    {
        cin>>c;
        c--;
        kk[c]=1;
    }
    c=0;
    fori(0,r)
    {
        c+=kk[i];
        if(kk[i]==0)
        {
            y=x;
            x=i;
        }
    }
    fori(r-1,n)
    {
        if(c==0)
        {
            kk[x]++;
            kk[y]++;
            t+=2;
            c=2;
        }
        if(c==1)
        {
            kk[x]++;
            t++;
            c=2;
        }
        c-=kk[i-r+1];
        c+=kk[i+1];
        if(kk[i+1]==0)
        {
            y=x;
            x=i+1;
        }
    }
    cout<<t<<endl;
    return 0;
}