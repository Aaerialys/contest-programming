#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

const int VV=1e5+1,LVL=20;
vector<int> gr[VV],len[VV];
int V,d,a,b,c,x,t,dep[VV],par[VV][LVL],m1[VV][LVL],m2[VV][LVL],cur,mm1,mm2;

void dfs(int v)
{
    fori(0,gr[v].size())
    {
        if(dep[gr[v][i]]>=dep[v]+1)
        {
            dep[gr[v][i]]=dep[v]+1;
            dfs(gr[v][i]);
        }
    }
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>V;
    fori(0,V-1)
    {
        dep[i+1]=INT_MAX;
        cin>>a>>b>>c; a--; b--;
        gr[a].push_back(b); gr[b].push_back(a);
        len[a].push_back(c); len[b].push_back(c);
    }
    cin>>d;
    dfs(0);
    par[0][0]=VV-1;
    fori(0,LVL)
        par[VV-1][i]=VV-1;
    fori(0,V)
    {
        forj(0,gr[i].size())
        {
            if(dep[gr[i][j]]<dep[i])
            {
                par[i][0]=gr[i][j];
                m1[i][0]=len[i][j];
            }
            else
            {
                par[gr[i][j]][0]=i;
                m1[gr[i][j]][0]=len[i][j];
            }
        }
    }
    fori(1,LVL)
        forj(0,V)
        {
            par[j][i]=par[par[j][i-1]][i-1];
            m2[j][i]=max(min(m1[j][i-1],m1[par[j][i-1]][i-1]),max(m2[j][i-1],m2[par[j][i-1]][i-1]));
            m1[j][i]=max(m1[j][i-1],m1[par[j][i-1]][i-1]);
        }
    fori(0,d)
    {
        cin>>a>>b; a--; b--; mm1=mm2=0;
        if(dep[a]>dep[b])
            swap(a,b);
        x=dep[b]-dep[a];
        fori(0,LVL)
            if(x&(1<<i))
            {
                mm2=max(mm2,max(m2[b][i],min(mm1,m1[b][i])));
                mm1=max(mm1,m1[b][i]);
                b=par[b][i];
            }
        fori(0,LVL)
        {
            if(par[a][LVL-i-1]!=par[b][LVL-i-1])
            {
                mm2=max(mm2,max(m2[a][LVL-i-1],min(mm1,m1[a][LVL-i-1])));
                mm1=max(mm1,m1[a][LVL-i-1]);
                a=par[a][LVL-i-1];
                mm2=max(mm2,max(m2[b][LVL-i-1],min(mm1,m1[b][LVL-i-1])));
                mm1=max(mm1,m1[b][LVL-i-1]);
                b=par[b][LVL-i-1];
            }
        }
        if(a!=b)
        {
            mm2=max(mm2,max(m2[a][0],min(mm1,m1[a][0])));
            mm1=max(mm1,m1[a][0]);
            mm2=max(mm2,max(m2[b][0],min(mm1,m1[b][0])));
            mm1=max(mm1,m1[b][0]);
            a=b=par[a][0];
        }
        if(mm2==0)
            cout<<"-1\n";
        else
            cout<<mm2<<"\n";
    }
    return 0;
}