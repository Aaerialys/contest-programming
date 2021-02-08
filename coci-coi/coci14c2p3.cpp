#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int n,k,gr[5010];
pair<int,int> sk[5010];
vector<int> lis;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    fori(0,n)
    {
        cin>>sk[i].first;
        sk[i].second=i;
    }
    sort(sk,sk+n);
    fori(0,n)
        gr[sk[i].second]=i/k;
    fori(0,n)
    {
        if(!lis.empty())
            k=lis.back();
        if(lis.empty()||gr[i]>=lis.back())
            lis.push_back(gr[i]);
        else
            lis[upper_bound(lis.begin(),lis.end(),gr[i])-lis.begin()]=gr[i];
    }
    cout<<n-lis.size();
    return 0;
}
/**
assign group to everyone;
find longest nondecreasing subsequence of the group numbers
answer=n-lis
*/