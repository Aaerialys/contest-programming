#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define seto(x,i) memset(x,i,sizeof x)
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define pf first
#define ps second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

bool p[10000001];
vector<int> prime;
int n;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("", "r", stdin);
    seto(p,1);
    fori(2,10000001)
        if(p[i])
        {
            for(int j=i*2;j<10000001;j+=i)
                p[j]=false;
            if(i>2)
                prime.push_back(i);
        }
    p[0]=p[1]=p[2]=false;
    fori(0,5)
    {
        cin>>n;
        if(p[n])
        {
            cout<<n<<" = "<<n<<"\n";
            continue;
        }
        ford(j,upper_bound(prime.begin(),prime.end(),n/2)-prime.begin()-1,0)
            if(p[n-prime[j]])
            {
                cout<<n<<" = "<<prime[j]<<" + "<<n-prime[j]<<"\n"; n=0;
                break;
            }
        ford(j,upper_bound(prime.begin(),prime.end(),n/3)-prime.begin()-1,0)
            ford(k,upper_bound(prime.begin(),prime.end(),(n-prime[j])/2)-prime.begin()-1,j)
                if(p[n-prime[j]-prime[k]])
                {
                    cout<<n<<" = "<<prime[j]<<" + "<<prime[k]<<" + "<<n-prime[j]-prime[k]<<"\n"; j=0;
                    break;
                }

    }
    return 0;
}