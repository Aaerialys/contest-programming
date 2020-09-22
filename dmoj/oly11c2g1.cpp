#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

int n,a[20010];
unordered_map<int,int> loc[5];

bool cmp(int x,int y)
{
    int t=0;
    fori(0,5)
        if(loc[i][x]<loc[i][y])
            t++;
    return t>=3;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    fori(0,5)
        forj(0,n)
        {
            cin>>a[j];
            loc[i][a[j]]=j;
        }
    sort(a,a+n,cmp);
    fori(0,n)
        cout<<a[i]<<"\n";
    return 0;
}