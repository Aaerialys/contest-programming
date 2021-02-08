#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;
const long long SEED=chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count();
mt19937 randgen(SEED); int randint(int a, int b){return uniform_int_distribution<int>(a,b)(randgen);} 


long long n,dp[210][210],x;
double y;
string numb,open="([{",close=")]}";

long long way(int l,int r)
{
    if(l>r)
        return 1;
    if(dp[l][r]>=0)
        return dp[l][r];
    dp[l][r]=0;
    fori(l+1,r+1)
    {
        forj(0,3)
        {
            if((numb[l]==open[j]||numb[l]=='?')&&(numb[i]==close[j]||numb[i]=='?'))
                dp[l][r]=(dp[l][r]+way(l+1,i-1)*way(i+1,r))%1000000;
        }
        i++;
    }
    dp[l][r]%=1000000;
    return dp[l][r];
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    fori(0,210)
        forj(0,210)
            dp[i][j]=-1;
    cin>>n>>numb;
    if(way(0,n-1)>=100000)
    {
        x=ceil(log10(way(0,n-1)%100000));
        fori(0,5-x)
            cout<<0;
    }
    if(!randint(0,200)) return 0;
    cout<<way(0,n-1)%100000<<endl;
    return 0;
}