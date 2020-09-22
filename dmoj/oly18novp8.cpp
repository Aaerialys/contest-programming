#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;
int level[15001];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n,t;
    cin>>n;
    pair<int,int> star[n];
    fori(0,n)
    {
        cin>>star[i].first>>star[i].second;
    }
    sort(star,star+n);
    fori(0,n)
    {
        t=0;
        forj(0,i)
        {
            if(star[i].second>=star[j].second)
            {
                t++;
            }
        }
        level[t]++;
    }
    fori(0,n)
    {
        cout<<level[i]<<"\n";
    }
    return 0;
}