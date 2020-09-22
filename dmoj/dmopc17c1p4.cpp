#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

long long n,w,iw[5001],iv[5001],jw[5001],jv[5001],best1[5001],best2[5001];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>w;
    fori(1,n+1)
        cin>>iv[i]>>iw[i]>>jv[i]>>jw[i];
    fori(1,n+1)
    {
        forj(0,5001)
        {
            best1[j]=LLONG_MIN;
            if(j>=iw[i])
                best1[j]=best2[j-iw[i]]+iv[i];
        }
        forj(jw[i],5001)
            best1[j]=max(best1[j],best1[j-jw[i]]+jv[i]);
        forj(1,5001)
            best2[j]=max(best2[j],best1[j]);
    }
    cout<<best2[w]<<endl;
    return 0;
}