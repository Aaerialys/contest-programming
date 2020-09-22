#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

double trade[510][510];
double worth[510];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int V,E,x=0,a,b,v;
    string s1,s2;
    unordered_map<string,int> name;
    double c;
    typedef pair<double,int> pii;
    bool ya=false;
    cin>>V>>E;
    vector<pii> gr[V];
    fori(0,V)
    {
        cin>>s1;
        name.emplace(s1,i);
        if(s1=="APPLES")
            x=i;
    }
    fori(0,V)
        forj(0,V)
            trade[i][j]=INT_MIN;
    for(int i=0;i<E;i++)
    {
        cin>>s1>>s2>>c;
        a=name[s1];
        b=name[s2];
        c=log(c);
        trade[a][b]=c;
    }
    queue<int> toVisit;
    for(int i=0;i<V;i++)
    {
        worth[i]=INT_MIN;
    }
    worth[x]=0;
    toVisit.push(x);
    while(!toVisit.empty()&&!ya)
    {
        v=toVisit.front();
        toVisit.pop();
        for(int i=0;i<V;i++)
        {
            if(worth[i]+0.00001<worth[v]+trade[v][i])
            {
                worth[i]=worth[v]+trade[v][i];
                toVisit.push(i);
                if(i==x)
                {
                    ya=true;
                }
            }
        }
    }
    if(ya)
        cout<<"YA";
    else
        cout<<"NAW";
}