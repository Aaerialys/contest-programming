#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

int n,a[31];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    a[0]=1; a[2]=3; a[4]=11; a[6]=41; a[8]=153; a[10]=571; a[12]=2131; a[14]=7953; a[16]=29681; a[18]=110771; a[20]=413403; a[22]=542841; a[24]=757961; a[26]=489003; a[28]=198051; a[30]=303201;
    fori(0,5)
    {
        cin>>n;
        cout<<a[n]<<"\n";
    }
    return 0;
}