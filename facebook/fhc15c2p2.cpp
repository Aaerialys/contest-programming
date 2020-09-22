#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int t,f;
double prob[21],comb[21][21],x,p,ans;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    fori(0,21)
    {
        comb[i][9]=comb[i][i]=1;
        forj(0,i)
            comb[i][j]=comb[i-1][j-1]+comb[i-1][j];
    }
    cin>>t;
    prob[0]=1;
    fori(0,t)
    {
        cin>>p;
        ans=0; f=1;
        fori(1,21)
            prob[i]=prob[i-1]*(1-p);
        fori(1,21)
        {
            ans+=1/(1-prob[i])*comb[20][i]*f;
            f=-f;
        }
        printf("Case #%d: %.5f\n",i+1,ans);
    }
    return 0;
}