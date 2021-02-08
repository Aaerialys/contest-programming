#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int n,h[501];
bool dp[25100],dif[51];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    fori(0,n)
        cin>>h[i];
    sort(h,h+n); reverse(h,h+n);
    dp[0]=dif[h[1]]=true;
    fori(2,n)
    {
        for(int j=50*n;j>=1;j--)
        {
            if(dp[j])
                continue;
            fork(0,51)
                if(dif[k]&&j>=k-h[i]&&dp[j-k+h[i]])
                    dp[j]=true;
        }
        dif[h[i]]=true;
    }
    fori(0,50*n)
        if(dp[i])
            cout<<i<<" ";
    return 0;
}
/**
sort pillar biggest first
dp[i][j]: is it possible for first i pillars to get j water
for each new pillar:
everything possible with i-1 pillars
swap ith and i-1th pillar, difference
everything possible with i-1 pillars + difference

*/