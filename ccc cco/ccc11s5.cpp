#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int k,x,ct=1,dp[30],sum[30],light[30];
pair<int,int> gr[30];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    fori(0,30)
        gr[i]={-1,-1};
    cin>>k;
    fori(0,k)
    {
        cin>>x; light[i]=x;
        if(x==0&&gr[ct].first>-1)
            ct++;
        if(x==1&&gr[ct].first==-1)
            gr[ct].first=i;
        if(x==1)
            gr[ct].second=i;
    }
    ct=0;
    fori(1,20)
        if(gr[i].first>-1)
            ct++;
    fori(1,ct+1)
        sum[i]=sum[i-1]+gr[i].second-gr[i].first+1;
    fori(1,ct+1)
    {
        dp[i]=dp[i-1]+4-(gr[i].second-gr[i].first+1);
        for(int j=i-1;j>0&&gr[i].first-gr[j].second<7;j--)
            if(gr[i].first-gr[j].second<5||light[(gr[i].first+gr[j].second)/2]==0||light[(gr[i].first+gr[j].second+1)/2]==0)
                dp[i]=min(dp[i],dp[j-1]+gr[i].second-gr[j].first+1-(sum[i]-sum[j-1]));
    }
    cout<<dp[ct];
    return 0;
}
/**
dp array3
divide into groups
ith group
first, how much to make ith group 4 long?
2nd, can you join the group with a previous one
if the previous group is less than 7 away
if the previous group does not form certain thing
if so, cost is total area between groups-number of lights on in that area;;;
lolololololololololololololololol;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
*/