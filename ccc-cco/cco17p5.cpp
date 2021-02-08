#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

pair<int,int> cct[200100];
int n,t,b;
multiset<int> cost;

bool cmp(pair<int,int> a,pair<int,int> b)
{
    if(a.first==b.first)
        return a.second<b.second;
    return a.first>b.first;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    fori(0,n)
    {
        cin>>cct[i].first>>cct[i].second;
    }
    sort(cct,cct+n,cmp);
    fori(0,n)
        cct[i].first-=n-i-1;
    fori(0,n)
    {
        cost.insert(cct[i].second);
        while(cct[i].first>b)
        {
            b++;
            t+=*cost.begin(); cost.erase(cost.begin());
        }
    }
    cout<<t<<endl;
    return 0;
}