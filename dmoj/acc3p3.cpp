#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

vector<int> pos[100010];
int n,m,x[100010],num;
string in[100010];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    fori(0,n)
    {
        cin>>in[i];
    }
    ford(i,25,0)
    {
        m=INT_MAX;
        forj(0,n)
        {
            pos[j].clear();
            fork(x[j],in[j].size())
                if(in[j][k]-'a'==i)
                    pos[j].push_back(k);
        }
        forj(0,n)
            m=min(m,(int)pos[j].size());
        if(m==0) continue;
        forj(0,n)
            x[j]=max(x[j],pos[j][m-1]);
        forj(0,m)
            cout<<(char)('a'+i);
        num+=m;
    }
    if(num==0)
        cout<<-1;
    cout<<endl;
    return 0;
}