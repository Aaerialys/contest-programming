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

const int N=100001;
int n,val[N],v,parent[N];

class djSet
{
public:
    djSet()
    {
        fori(0,N)
            parent[i]=i;
    }
    int lead(int x)
    {
        if(parent[x]!=x)
            parent[x]=lead(parent[x]);
        return parent[x];
    }
    bool link(int x,int y)
    {
        x=lead(x);
        y=lead(y);
        parent[x]=y;
        val[y]=max(val[x],val[y]);
        return x==y;
    }
};

unordered_map<string,int> var;
string s1[N],s2[N];
bool pos;
djSet djs;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("zamjena.in.3f", "r", stdin);
    cin>>n; pos=true;
    fori(0,n)
        cin>>s1[i];
    fori(0,n)
        cin>>s2[i];
    fori(0,n)
    {
        if(isdigit(s1[i][0])&&isdigit(s2[i][0]))
        {
            pos&=(stoi(s1[i])==stoi(s2[i]));
            continue;
        }
        if(!isdigit(s1[i][0])&&var[s1[i]]==0)
            var[s1[i]]=++v;
        if(!isdigit(s2[i][0])&&var[s2[i]]==0)
            var[s2[i]]=++v;
        if(isdigit(s2[i][0]))
            swap(s1[i],s2[i]);
        if(isdigit(s1[i][0]))
        {
            if(val[djs.lead(var[s2[i]])]!=0&&val[djs.lead(var[s2[i]])]!=stoi(s1[i]))
                pos=false;
            val[djs.lead(var[s2[i]])]=stoi(s1[i]);
        }
        else
        {
            if(val[djs.lead(var[s1[i]])]!=val[djs.lead(var[s2[i]])]&&min(val[djs.lead(var[s1[i]])],val[djs.lead(var[s2[i]])])!=0)
                pos=false;
            djs.link(var[s1[i]],var[s2[i]]);
        }
    }
    cout<<(pos? "DA": "NE");
    return 0;
}