#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

int n,tim[1<<15][2],sp[15],p[15]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,1<<14};

int cross(int mask,bool side)
{
    if(tim[mask][side]!=INT_MAX/2)
        return tim[mask][side];
    if(side)
    {
        if(mask==0)
            return 0;
        fori(0,n)
            if((mask&p[i])==0)
                return tim[mask][1]=cross(mask|p[i],0)+sp[i];
    }
    fori(0,n)
        if(mask&p[i])
            forj(0,i)
                if(i!=j&&mask&p[j])
                    tim[mask][0]=min(tim[mask][side],cross(mask&(~p[i])&(~p[j]),1)+max(sp[i],sp[j]));
    return tim[mask][0];
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    fori(0,1<<15)
        tim[i][0]=tim[i][1]=INT_MAX/2;
    cin>>n;
    fori(0,n)
        cin>>sp[i];
    if(n==1)
    {
        cout<<sp[0];
        return 0;
    }
    sort(sp,sp+n);
    cout<<cross((1<<n)-1,0);
    return 0;
}