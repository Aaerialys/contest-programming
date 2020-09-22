#include <bits/stdc++.h>

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int V,q,x,y,aa,bb;
    cin>>V>>q;
    int lit[V][3];
    for(int i=0;i<V;i++)
    {
        cin>>lit[i][0]>>lit[i][1]>>lit[i][2];
    }
    queue<int> toVisit;
    int dist[V];
    int v;
    for(int a=0;a<q;a++)
    {
        cin>>x>>y;
        x--;
        y--;
        for(int i=0;i<V;i++)
        {
            dist[i]=INT_MAX;
        }
        dist[x]=0;
        toVisit.push(x);
        while(toVisit.empty()==false)
        {
            v=toVisit.front();
            toVisit.pop();
            for(int i=0;i<V;i++)
            {
                aa=pow(lit[v][0]-lit[i][0],2)+pow(lit[v][1]-lit[i][1],2);
                bb=pow(lit[v][2],2);
                if(aa<=bb&&dist[i]==INT_MAX)
                {
                    dist[i]=0;
                    toVisit.push(i);
                }
            }
        }
        if(dist[y]==INT_MAX)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
    return 0;
}