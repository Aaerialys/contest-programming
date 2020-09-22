#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

class node
{
public:
    long long v,p,sz,n,sm;
    node *left, *right;
    node(long long x)
    {
        sm=v=x;
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
    long long sz(node *n)
    {
        if(n!=nullptr)
            return n->sz;
        return 0;
    }
    long long sm(node *n)
    {
        if(n!=nullptr)
            return n->sm;
        return 0;
    }
    void updsz(node *n)
    {
        if(n!=nullptr)
        {
            n->sz=sz(n->left)+sz(n->right)+n->n;
            n->sm=sm(n->left)+sm(n->right)+(n->v)*(n->n);
        }
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
    void ins(long long x)
    {
        if(rt==nullptr)
            rt=new node(x);
        else
            ins(x,rt);
    }
    void ins(long long x,node *&n)
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
    void del(long long x)
    {
        del(rt,x);
    }
    void del(node *&n,long long x)
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
    long long element(long long x)
    {
        if(x<=0||x>rt->sz)
            return -1;
        return element(x,rt)->v;
    }
    node* element(long long x, node *n)
    {
        if(sz(n->left)>=x)
            return element(x,n->left);
        else if(sz(n->left)+n->n>=x)
            return n;
        return element(x-sz(n->left)-n->n,n->right);
    }
    long long sum(long long x)
    {
        return sum(x,rt);
    }
    long long sum(long long x,node *n)
    {
        if(n==nullptr)
            return 0;
        if(sz(n->left)>=x)
            return sum(x,n->left);
        else if(sz(n->left)+n->n>=x)
            return sm(n->left)+(n->v)*(x-sz(n->left));
        return sum(x-sz(n->left)-n->n,n->right)+sm(n->left)+(n->v)*(n->n);
    }
};

bool cmp(pair<int,int> a,pair<int,int> b)
{
    return a.first+a.second<b.first+b.second;
}

treap p,q;
long long k,N,n,b,d,y,z,t,t1;
char a,c;
vector<pair<long long,long long>> pla;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>k>>N;
    fori(0,N)
    {
        cin>>a>>b>>c>>d;
        if(a!=c)
        {
            pla.push_back(make_pair(min(b,d),max(b,d)));
            p.ins(b);p.ins(d);
            n++;
        }
        else
            t1+=abs(b-d);
    }
    sort(pla.begin(),pla.end(),cmp);
    b=p.sz(p.rt);
    t=p.sum(b)-p.sum(b/2)*2-p.element(b/2)*(b-b/2-b/2);
    if(k==1)
    {
        cout<<t+t1+n;
        return 0;
    }
    fori(0,n-1)
    {
        p.del(pla[i].first);p.del(pla[i].second);
        q.ins(pla[i].first);q.ins(pla[i].second);
        b=p.sz(p.rt);
        d=q.sz(q.rt);
        t=min(t,p.sum(b)-p.sum(b/2)*2-p.element(b/2)*(b-b/2-b/2)+q.sum(d)-q.sum(d/2)*2-q.element(d/2)*(d-d/2-d/2));
    }
    cout<<t+t1+n;
    return 0;
}