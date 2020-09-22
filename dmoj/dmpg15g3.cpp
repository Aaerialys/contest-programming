#include <bits/stdc++.h>
#define fori(a,b) for(long long i=a;i<(long long)b;i++)
#define forj(a,b) for(long long j=a;j<(long long)b;j++)
#define fork(a,b) for(long long k=a;k<(long long)b;k++)
#define ford(i,a,b) for(long long i=a;i>=(long long)b;i--)

using namespace std;

class node
{
public:
    int p,sz,n,v;
    node *left,*right;
    node(int x)
    {
        v=x;
        p=rand();
        left=right=nullptr;
        sz=n=1;
    }
};
class treap
{
public:
    node *rt;
    treap()
    {
        rt=nullptr;
    }
    int sz(node *n)
    {
        if(n!=nullptr)
            return n->sz;
        return 0;
    }
    void updsz(node *n)
    {
        if(n!=nullptr)
            n->sz=sz(n->left)+sz(n->right)+n->n;
    }
    void lrot(node *&n)
    {
        node *temp=n->left; n->left=temp->right; temp->right=n;
        updsz(n); updsz(temp);
        n=temp;
    }
    void rrot(node *&n)
    {
        node *temp=n->right; n->right=temp->left; temp->left=n;
        updsz(n); updsz(temp);
        n=temp;
    }
    void ins(int x)
    {
        if(rt==nullptr)
            rt=new node(x);
        else
            ins(x,rt);
    }
    void ins(int x,node *&n)
    {
        if(x==n->v)
            (n->n)++;
        else if(x<n->v)
        {
            if(n->left==nullptr)
                n->left=new node(x);
            else
                ins(x,n->left);
            if(n->left->p<n->p)
                lrot(n);
        }
        else if(x>n->v)
        {
            if(n->right==nullptr)
                n->right=new node(x);
            else
                ins(x,n->right);
            if(n->right->p<n->p)
                rrot(n);
        }
        updsz(n);
    }
    void del(int x)
    {
        del(rt,x);
    }
    void del(node *&n,int x)
    {
        if(n==nullptr)
            return;
        if(n->v>x)
            del(n->left,x);
        if(n->v<x)
            del(n->right,x);
        if(n->v==x)
        {
            if(n->n>1)
                (n->n)--;
            else if(n->left==nullptr&&n->right==nullptr)
            {
                delete n; n=nullptr;
            }
            else if(n->left==nullptr)
            {
                node *temp=n->right;
                delete n; n=temp;
            }
            else if(n->right==nullptr)
            {
                node *temp=n->left;
                delete n; n=temp;
            }
            else
            {
                if(n->left->p>n->right->p)
                {
                    lrot(n);
                    del(n->right,x);
                }
                else if(n->right->p>n->left->p)
                {
                    rrot(n);
                    del(n->left,x);
                }
            }
        }
        updsz(n);
    }
    int index(int v)
    {
        if(rt==nullptr)
            return 0;
        return index(v,rt);
    }
    long long index(int v,node *n)
    {
        if(n->v>v&&n->left!=nullptr)
            return index(v,n->left);
        else if(n->v>v)
            return 0; ///1 for round up, 0 for round down
        if(n->v<v&&n->right!=nullptr)
            return index(v,n->right)+sz(n->left)+n->n;
        else if(n->v<v)
            return sz(n->left)+n->n;
        return sz(n->left)+n->n;
    }
};

const long long N=200100;
long long n,lk,rk,lc,rc,x,y,z,d1[N],d2[N],t,a,b,sz[N],par[N],lvl[N],cur,cur2;
vector<int> gr[N];
vector<pair<long long,long long>> dist,dist2;
bool blc[N],kin[N],cros[N];
queue<long long> sub;
char ch;

void sizedfs(long long v,long long p)
{
    sz[v]=1;
    fori(0,gr[v].size())
    {
        if(gr[v][i]!=p&&!blc[gr[v][i]])
        {
            sizedfs(gr[v][i],v);
            sz[v]+=sz[gr[v][i]];
        }
    }
}
long long getCenter(long long v,long long p,long long tot)
{
    fori(0,gr[v].size())
        if(gr[v][i]!=p&&!blc[gr[v][i]]&&sz[gr[v][i]]*2>tot)
            return getCenter(gr[v][i],v,tot);
    blc[v]=true;
    return v;
}
void dfs(long long p,long long v)
{
    d1[v]=d1[p]+kin[v];
    d2[v]=d2[p]+cros[v];
    dist.push_back({d1[v],d2[v]});
    dist2.push_back({d1[v],d2[v]});
    for(auto i:gr[v])
        if(i!=p&&lvl[i]>lvl[cur])
        {
            dfs(v,i);
        }
    d1[v]=d2[v]=0;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>lk>>rk>>lc>>rc;
    fori(0,n)
    {
        cin>>ch;
        if(ch=='K')
            kin[i]=true;
        if(ch=='C')
            cros[i]=true;
    }
    fori(0,n-1)
    {
        cin>>x>>y; x--; y--;
        gr[x].push_back(y);
        gr[y].push_back(x);
    }
    sub.push(0); par[0]=-1;
    while(!sub.empty())
    {
        x=sub.front(); sub.pop();
        sizedfs(x,x);
        y=getCenter(x,x,sz[x]);
        par[y]=par[x];
        if(par[y]!=-1)
            lvl[y]=lvl[par[y]]+1;
        fori(0,gr[y].size())
        {
            if(!blc[gr[y][i]])
            {
                sub.push(gr[y][i]);
                par[gr[y][i]]=y;
            }
        }
    }
    fori(0,n)
    {
        treap tr;
        dist.clear();
        cur=i;
        dist.push_back({d1[i],d2[i]});
        for(auto j:gr[i])
        {
            if(lvl[j]<lvl[cur]) continue;
            cur2=j;
            dist2.clear();
            dfs(i,j);
            treap tr2;
            sort(dist2.begin(),dist2.end());
            x=dist2.size(); y=dist2.size()-1;
            fork(0,dist2.size())
            {
                for(;x>0&&dist2[x-1].first>=lk-dist2[k].first-kin[i];x--)
                    tr2.ins(dist2[x-1].second);
                for(;y>=0&&dist2[y].first>rk-dist2[k].first-kin[i];y--)
                    tr2.del(dist2[y].second);
                a=tr2.index(rc-dist2[k].second-cros[i])-tr2.index(lc-dist2[k].second-cros[i]-1);
                if(dist2[k].first>=lk-dist2[k].first-kin[i]&&dist2[k].first<=rk-dist2[k].first-kin[i]&&dist2[k].second>=lc-dist2[k].second-cros[i]&&dist2[k].second<=rc-dist2[k].second-cros[i])
                    a++;
                t-=a;
            }
        }
        sort(dist.begin(),dist.end());
        x=dist.size(); y=dist.size()-1;
        forj(0,dist.size())
        {
            for(;x>0&&dist[x-1].first>=lk-dist[j].first-kin[i];x--)
                    tr.ins(dist[x-1].second);
            for(;y>=0&&dist[y].first>rk-dist[j].first-kin[i];y--)
                tr.del(dist[y].second);
            a=tr.index(rc-dist[j].second-cros[i])-tr.index(lc-dist[j].second-cros[i]-1);
            if(dist[j].first>=lk-dist[j].first-kin[i]&&dist[j].first<=rk-dist[j].first-kin[i]&&dist[j].second>=lc-dist[j].second-cros[i]&&dist[j].second<=rc-dist[j].second-cros[i])
                a++;
            t+=a;
        }
    }
    t/=2;
    cout<<t;
    return 0;
}