#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

string str;
int t;
int dp[301][301];

int best(int l,int r)
{
    if(dp[l][r])
        return dp[l][r];
    if(l>r)
        return 0;
    if(l==r)
        return 1;
    int x=INT_MAX/4;
    if((str[l]=='('&&str[r]==')')||(str[l]=='['&&str[r]==']'))
        x=best(l+1,r-1);
    else{
        x=best(l+1,r-1)+2;
    }
    fori(l,r)
        x=min(x,best(l,i)+best(i+1,r));
    return dp[l][r]=x;
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>str;
    cout<<best(0,str.size()-1);
    return 0;
}