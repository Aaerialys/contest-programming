#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

const int N=2001110;
vector<int> axis[N];
int n,x,L,R,l,r,m,ans,card[N],fix[N];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    fori(1,n+1)
    {
        cin>>card[i*2]; card[i*2]*=2;
        axis[(i*2+card[i*2])/2].push_back(abs(i*2-(i*2+card[i*2])/2));
        if(card[i*2]==i*2)
            fix[i*2]++;
        fix[i*2+2]=fix[i*2+1]=fix[i*2];
    }
    fori(0,n*2+10)
    {
        if(axis[i].empty())
            continue;
        m=0;
        sort(axis[i].begin(),axis[i].end());
        forj(0,axis[i].size())
        {
            if(m<=j+1-(fix[i+axis[i][j]]-fix[i-axis[i][j]-1]))
            {
                m=j+1-(fix[i+axis[i][j]]-fix[i-axis[i][j]-1]);
                r=i+axis[i][j];
                l=i-axis[i][j];
            }
        }
        if(axis[i][0]==0)
            m++;
        if(m>ans)
        {
            ans=m;
            L=l;
            R=r;
        }
    }
    cout<<card[L]/2<<" "<<card[R]/2<<endl;
    return 0;
}