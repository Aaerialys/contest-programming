#include <bits/stdc++.h>
#define fori(a,x) for (int i=a; i<(x); i++)
#define forj(a,x) for (int j=a; j<(x); j++)
#define fork(a,x) for (int k=a; k<(x); k++)

using namespace std;

int V;
vector<int> parent;
vector<int> depth;
vector<int> sizet;
stack<int> oldhead;
void Init(int N)
{
    V=N;
    parent.reserve(500010);
    depth.reserve(500010);
    sizet.reserve(500010);
    fori(0,500010)
    {
        parent[i]=i;
        depth[i]=1;
        sizet[i]=1;
    }
}
int lead(int x)
{
    if(parent[x]!=x)
    {
        return lead(parent[x]);
    }
    return parent[x];
}
void AddEdge(int U,int V)
{
    int x=U,y=V;
    x=lead(x);
    y=lead(y);
    if(x==y)
        oldhead.push(500001);
    else if(depth[x]>depth[y])
    {
        parent[y]=x;
        oldhead.push(y);
        sizet[x]+=sizet[y];
    }
    else
    {
        oldhead.push(x);
        parent[x]=y;
        sizet[y]+=sizet[x];
        if(depth[x]==depth[y])
            depth[y]++;
    }
}
void RemoveLastEdge()
{
    if(!oldhead.empty())
    {
        sizet[parent[oldhead.top()]]-=sizet[oldhead.top()];
        parent[oldhead.top()]=oldhead.top();
        oldhead.pop();
    }
}
int GetSize(int U)
{
    return sizet[lead(U)];
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    Init(10);
    AddEdge(1,2);
    AddEdge(4,5);
    AddEdge(5,3);
    AddEdge(9,7);
    AddEdge(6,5);
    AddEdge(2,3);
    AddEdge(7,8);
    fori(0,V) cout<<GetSize(i)<<" ";
    cout<<endl;
    RemoveLastEdge();
    fori(0,V) cout<<GetSize(i)<<" ";
    cout<<endl;
    RemoveLastEdge();
    fori(0,V) cout<<GetSize(i)<<" ";
    cout<<endl;
    return 0;
}