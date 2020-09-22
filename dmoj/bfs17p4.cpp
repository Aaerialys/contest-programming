#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int n;
char ch;
string str;
int rite[100000],ma[100000],mi[100000],siz[100000];
vector<int> nxt[100000];

void pos(int x)
{
    int m1,m2,n1,n2,a,b;
    m1=n1=m2=n2=0;
    siz[x]=1;
    fori(0,nxt[x].size())
    {
        a=nxt[x][i];
        pos(a);
        siz[x]+=siz[a];
    }
    if(rite[x]==1||rite[x]==0)
    {
        fori(0,nxt[x].size())
        {
            a=nxt[x][i];
            m1+=ma[a];
            n1+=mi[a];
        }
    }
    else
        n1=INT_MAX;
    if(rite[x]==-1||rite[x]==0)
    {
        fori(0,nxt[x].size())
        {
            a=nxt[x][i];
            n2+=ma[a];
            m2+=mi[a];
        }
        m2=siz[x]-m2;
        n2=siz[x]-n2;
    }
    else
        n2=INT_MAX;
    ma[x]=max(m1,m2);
    mi[x]=min(n1,n2);
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int a,b;
    cin>>n;
    n++;
    rite[0]=1;
    fori(1,n)
    {
        cin>>ch;
        a=0;
        if(ch=='E')
        {
            cin>>a;
        }
        nxt[a].push_back(i);
        cin>>str;
        rite[i]=0;
        if(str=="AC")
            rite[i]=1;
        if(str=="WA")
            rite[i]=-1;

    }
    pos(0);
    cout<<mi[0]<<" "<<ma[0]<<endl;
    return 0;
}