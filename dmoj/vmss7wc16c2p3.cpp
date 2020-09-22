#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n,m,x;
    int jeff[1000001];
    cin>>n;
    for(int i=0;i<1000001;i++)
        jeff[i]=INT_MAX;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        jeff[x]=i;
    }
    cin>>m;
    int same[m];
    for(int i=0;i<m;i++)
    {
        cin>>x;
        same[i]=jeff[x];
    }
    vector<int> lng;
    for(int i=0;i<m;i++)
    {
        if(same[i]!=INT_MAX)
        {
            if(lng.empty()||same[i]>lng.back())
                lng.push_back(same[i]);
            else
                lng[lower_bound(lng.begin(),lng.end(),same[i])-lng.begin()]=same[i];
        }
    }
    cout<<lng.size();
    return 0;
}