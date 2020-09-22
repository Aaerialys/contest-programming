#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;
bool gr[110][110];
int dist[110];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin>>T;
    fork(0,T)
    {
        int n,m,x,v;
        unordered_map<string,int> name;
        string str0,str1;
        fori(0,110)
        {
            forj(0,110)
                gr[i][j]=false;
        }
        cin>>m>>str0;
        n=0;
        name.emplace(str0,n);
        fori(1,m)
        {
            cin>>str1;
            if(name.count(str1)==0)
            {
                n++;
                name.emplace(str1,n);
            }
            gr[name[str0]][name[str1]]=true;
            gr[name[str1]][name[str0]]=true;
            str0=str1;
        }
        x=name[str0];
        n++;
        queue<int> toV;
        fori(0,n)
            dist[i]=INT_MAX;
        dist[x]=0;
        toV.push(x);
        while(!toV.empty())
        {
            v=toV.front();
            toV.pop();
            fori(0,n)
            {
                if(gr[v][i]&&dist[i]>dist[v]+1)
                {
                    dist[i]=dist[v]+1;
                    toV.push(i);
                }
            }
        }
        x=-1;
        fori(0,n)
        {
            if(dist[i]!=INT_MAX)
                x=max(x,dist[i]);
        }
        cout<<m*10-x*20<<"\n";
    }
    return 0;
}