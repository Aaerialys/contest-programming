#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

const int N=500001;
int n,a,mob[N],to[N],fr[N];
stack<int> toV;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    fori(0,n)
    {
        cin>>a; a--;
        to[i]=a; fr[a]++;
    }
    fori(0,n)
        if(fr[i]==0)
            toV.push(i);
    while(!toV.empty())
    {
        a=toV.top(); toV.pop();
        if(mob[a]!=0)
            continue;
        mob[a]=1; a=to[a];
        if(mob[a]!=0)
            continue;
        mob[a]=2; a=to[a];
        if(mob[a]!=0)
            continue;
        fr[a]--;
        if(fr[a]==0)
            toV.push(a);
    }
    fori(0,n)
        if(mob[i]==0)
        {
            mob[i]=2;
            fr[to[i]]--;
            if(mob[to[i]]==0&&fr[to[i]]==0)
                toV.push(to[i]);
            while(!toV.empty())
            {
                a=toV.top(); toV.pop();
                if(mob[a]!=0)
                    continue;
                mob[a]=1; a=to[a];
                if(mob[a]!=0)
                    continue;
                mob[a]=2; a=to[a];
                if(mob[a]!=0)
                    continue;
                fr[a]--;
                if(fr[a]==0)
                    toV.push(a);
            }
        }
    a=0;
    fori(0,n)
        if(mob[i]==1)
            a++;
    cout<<a<<"\n";
    return 0;
}
/**
start indegree 0, is mobster
accused by mobster, must be civillian
if civillian, remove the node
repeat until no one left with indegree 0 (all cycle)
pick random unvisited node as civillian, alternate mobster civillian
repeat for each cycle
count mobsters

*/