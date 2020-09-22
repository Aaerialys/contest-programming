#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int d,t,a,b,c,v;
    cin>>d;
    int wait[d],time[d],bark[d];
    vector<int> hear[d];
    fori(0,d)
    {
        cin>>wait[i];
        time[i]=-1;
        bark[i]=0;
    }
    cin>>a;
    fori(0,a)
    {
        cin>>b>>c;
        b--;
        c--;
        hear[b].push_back(c);
    }
    cin>>t;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> toV;
    bark[0]=1;
    time[0]=0;
    toV.push(make_pair(0,0));
    while(!toV.empty())
    {
        v=toV.top().second;
        toV.pop();
        c=hear[v].size();
        fori(0,c)
        {
            a=hear[v][i];
            if(time[a]<time[v])
            {
                time[a]=time[v]+wait[a];
                if(time[a]<=t)
                {
                    toV.push(make_pair(time[a],a));
                    bark[a]++;
                }
            }
        }
    }
    fori(0,d)
        cout<<bark[i]<<"\n";
    return 0;
}