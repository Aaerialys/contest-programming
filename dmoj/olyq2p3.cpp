#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

long long n,ki,dp[12][102][1030],t;
vector<int> pos;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>ki;
    fori(0,1<<n)
        if((i&(i<<1))==0)
            pos.push_back(i);
    dp[0][0][0]=1;
    fori(1,n+1)
        forj(0,ki+1)
            fork(0,pos.size())
                if(j>=__builtin_popcount(pos[k]))
                    for(int l=0;l<pos.size();l++)
                        if((pos[k]&pos[l])+(pos[k]&pos[l]*2)+(pos[k]&pos[l]/2)==0)
                            dp[i][j][pos[k]]+=dp[i-1][j-__builtin_popcount(pos[k])][pos[l]];
    fori(0,pos.size())
        t+=dp[n][ki][pos[i]];
    cout<<t<<endl;
    return 0;
}