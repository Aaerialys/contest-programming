#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

string s;
long long n,t,snum[5001],B=26,M=1e9+7,p[5001]={1};
long long x,y,z,pre;
unordered_set<int> pos;

long long num(int l,int r)
{
    return (snum[r]-snum[l-1]*p[r-l+1]%M+M)%M;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    fori(1,5001)
        p[i]=p[i-1]*B%M;
    cin>>s; s='.'+s;
    snum[0]=0; n=s.size();
    forj(1,n)
        snum[j]=(snum[j-1]*B%M+s[j]-'a'+1)%M;
    fori(1,n/2+1)
    {
        t=i*2+1;
        forj(i,t)
        {
            y=num(j-i+1,j); pre=j-i+1;
            for(int k=j+i;k<n;k+=i)
            {
                z=num(k-i+1,k);
                if(y==z)
                    pos.insert(num(pre,k));
                else
                {
                    pre=k-i+1;
                    y=z;
                }

            }
        }
    }
    cout<<pos.size();
    return 0;
}