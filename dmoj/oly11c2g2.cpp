#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;
struct edge
{
    int a,b,c=INT_MAX;
};
bool cmp(edge x,edge y)
{
    return x.c<y.c;
}
class djSet
{
public:
    int parent[40010];
    djSet(int n)
    {
        fori(0,n)
            parent[i]=i;
    }
    int lead(int x)
    {
        if(parent[x]!=x)
            parent[x]=lead(parent[x]);
        return parent[x];
    }
    void link(int x,int y)
    {
        x=lead(x);
        y=lead(y);
        parent[x]=y;
    }
};

djSet djs(40010);
long long V,E,x,y,z,s=1,t,n,M=1e9+7;
edge gr[100010];

int main()
{
    cin>>V>>E;
    fori(0,E)
    {
        cin>>gr[i].a>>gr[i].b>>gr[i].c;
        gr[i].a--; gr[i].b--;
    }
    sort(gr,gr+E,cmp);
    fori(0,E)
    {
        if(djs.lead(gr[i].a)!=djs.lead(gr[i].b))
        {
            x=1;
            if(gr[i].c==gr[i+1].c&&max(djs.lead(gr[i+1].a),djs.lead(gr[i+1].b))==max(djs.lead(gr[i].a),djs.lead(gr[i].b))&&min(djs.lead(gr[i+1].a),djs.lead(gr[i+1].b))==min(djs.lead(gr[i].a),djs.lead(gr[i].b)))
                x++;
            if(gr[i].c==gr[i+2].c&&max(djs.lead(gr[i+2].a),djs.lead(gr[i+2].b))==max(djs.lead(gr[i].a),djs.lead(gr[i].b))&&min(djs.lead(gr[i+2].a),djs.lead(gr[i+2].b))==min(djs.lead(gr[i].a),djs.lead(gr[i].b)))
                x++;
            s=s*x%M;
            if(x==1&&gr[i].c==gr[i+1].c&&gr[i].c==gr[i+2].c&&djs.lead(gr[i+1].a)!=djs.lead(gr[i+1].b)&&max(djs.lead(gr[i+1].a),djs.lead(gr[i+1].b))==max(djs.lead(gr[i+2].a),djs.lead(gr[i+2].b))&&min(djs.lead(gr[i+1].a),djs.lead(gr[i+1].b))==min(djs.lead(gr[i+2].a),djs.lead(gr[i+2].b)))
            {
                x=0;
                s=s*2%M;
                djs.link(gr[i+1].a,gr[i+1].b);
                t=(t+gr[i].c);
                n++;
            }
            djs.link(gr[i].a,gr[i].b);
            if(x==1&&gr[i].c==gr[i+1].c&&gr[i].c==gr[i+2].c&&djs.lead(gr[i+1].a)!=djs.lead(gr[i+1].b)&&max(djs.lead(gr[i+1].a),djs.lead(gr[i+1].b))==max(djs.lead(gr[i+2].a),djs.lead(gr[i+2].b))&&min(djs.lead(gr[i+1].a),djs.lead(gr[i+1].b))==min(djs.lead(gr[i+2].a),djs.lead(gr[i+2].b)))
            {
                s=s*3%M;
                djs.link(gr[i+1].a,gr[i+1].b);
                t=(t+gr[i].c);
                n++;
            }
            t=(t+gr[i].c);
            n++;
        }
    }
    if(n<V-1)
        cout<<"0 1";
    else
        cout<<t<<" "<<s;
    return 0;
}
/*
5 6
0 4 1
4 3 1
0 3 1
4 1 2
1 2 2
2 4 2

*/