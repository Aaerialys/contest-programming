#include <bits/stdc++.h>
using namespace std; int n,K,t,rk[25][25],o; bool pos;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("gymnastics.in", "r", stdin); freopen("gymnastics.out", "w", stdout);
    cin>>K>>n;
    for(int i=0;i<K;i++) for(int j=0;j<n;j++){ cin>>t; t--; rk[t][i]=j;}
    t=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<i;j++)
        {
            o=0; pos=1;
            for(int k=0;k<K;k++)
            {
                if(rk[i][k]>rk[j][k])
                {
                    if(o==-1)
                        pos=false;
                    o=1;
                }
                if(rk[i][k]<rk[j][k])
                {
                    if(o==1)
                        pos=false;
                    o=-1;
                }
            }
            if(pos)
                t++;
        }
    cout<<t;
    return 0;
}
/**

*/
