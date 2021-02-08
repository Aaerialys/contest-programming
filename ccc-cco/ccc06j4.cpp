#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
queue<int> order;
int gr[8][8]={{0,0,0,0,0,0,0}
            ,{0,0,0,0,1,0,0,1}
            ,{0,1,0,0,0,0,0,0}
            ,{0,0,0,0,1,1,0,0}
            ,{0,0,0,0,0,0,0,0}
            ,{0,0,0,0,0,0,0,0}
            ,{0,0,0,0,0,0,0,0}
            ,{0,0,0,0,0,0,0,0}};

int topS(int V)
{
    int in[V]={0},c=0,v;
    vector <int> toV;
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            if(gr[j][i]==1)
            {
                in[i]++;
            }
        }
    }
    for(int i=0;i<V;i++)
    {
        if(in[i]==0)
        {
            toV.push_back(i);
        }
    }
    while(toV.empty()==false)
    {
        sort(toV.begin(),toV.end());
        v=toV.front();
        order.push(v);
        toV.erase(toV.begin());
        c++;
        for(int i=0;i<V;i++)
        {
            if(gr[v][i]==1)
            {
                in[i]--;
                if(in[i]==0)
                {
                    toV.push_back(i);
                }
            }
        }
    }
    if(c!=V)
    {
        return 1;
    }
    return 0;
}
int main()
{
    int x,y;
    cin>>x>>y;
    while(x!=0&&y!=0)
    {
        gr[x][y]=1;
        cin>>x>>y;
    }
    if(topS(8)==1)
    {
        cout<<"Cannot complete these tasks. Going to bed.";
    }
    else
    {
        if(order.front()==0)
            order.pop();
        while(order.empty()==false)
        {
            cout<<order.front()<<" ";
            order.pop();
        }
    }
    return 0;
}