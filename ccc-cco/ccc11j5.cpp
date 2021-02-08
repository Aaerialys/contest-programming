#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int group[10];
vector<int> invite[10];

int zucc(int a)
{
    if(group[a]!=0)
        return group[a];
    if(invite[a].size()==0)
    {
        return group[a]=2;
    }
    group[a]=1;
    fori(0,invite[a].size())
    {
        group[a]*=zucc(invite[a][i]);
    }
    group[a]++;
    return group[a];
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n,a;
    cin>>n;
    fori(0,n-1)
    {
        cin>>a;
        invite[a-1].push_back(i);
    }
    cout<<zucc(n-1)-1<<endl;
    return 0;
}