#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int l,n,a,b,x,m;
    vector<pair<int,bool>> ani;
    cin>>l>>n;
    ani.push_back(make_pair(l-1,0));
    ani.push_back(make_pair(0,1));
    fori(0,n)
    {
        cin>>a>>b;
        ani.push_back(make_pair(a,0));
        ani.push_back(make_pair(b,1));
    }
    sort(ani.begin(),ani.end());
    m=0;
    x=1;
    fori(0,ani.size())
    {
        if(ani[i].second==0)
            x++;
        else
            x--;
        if(x==0)
            m=max(m,ani[i+1].first-ani[i].first);
    }
    cout<<m;
    return 0;
}