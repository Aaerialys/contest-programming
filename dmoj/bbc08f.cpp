#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;
int N,X,s,e;
pair<int,int> a[5002];
long long tot;
int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>X;
    s=e=X;
    fori(1,N+1)
    {
        cin>>a[i].first>>a[i].second;
        if(s>a[i].second)
        {
            tot+=abs(s-a[i].second);
            e=s;
            s=a[i].second;
        }
        else if(e<a[i].first)
        {
            tot+=abs(a[i].first-e);
            s=e;
            e=a[i].first;
        }
        else
        {
            s=max(s,a[i].first);
            e=min(e,a[i].second);
        }
    }
    cout<<tot;
    return 0;
}