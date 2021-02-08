#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

const int NN=10010;
class node
{
public:
    int v,p,sz,n,v2;
    node *left, *right;
    node(int x,int y)
    {
        v=x;
        v2=y;
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
    void ins(int x,int y)
    {
        if(rt==nullptr)
            rt=new node(x,y);
        else
            ins(x,y,rt);
    }
    void ins(int x,int y,node *&n)
    {
        if(x==n->v)
        {
            (n->n)++;
            n->v2+=y;
        }
        else if(x<n->v)
        {
            if(n->left==nullptr)
                n->left=new node(x,y);
            else
                ins(x,y,n->left);
            if(n->left->p<n->p)
                lrot(n);
        }
        else if(x>n->v)
        {
            if(n->right==nullptr)
                n->right=new node(x,y);
            else
                ins(x,y,n->right);
            if(n->right->p<n->p)
                rrot(n);
        }
        updsz(n);
    }
    void del(int x,int y)
    {
        del(rt,x,y);
    }
    void del(node *&n,int x,int y)
    {
        if(n==nullptr)
            return;
        if(n->v>x)
            del(n->left,x,y);
        if(n->v<x)
            del(n->right,x,y);
        if(n->v==x)
        {
            if(n->n>1)
            {
                (n->n)--;
                n->v2-=y;
            }
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
                    del(n->right,x,y);
                }
                else if(n->right->p>n->left->p)
                {
                    rrot(n);
                    del(n->left,x,y);
                }
            }
        }
        updsz(n);
    }
    int xx,last,t;
    int len()
    {
        xx=last=t=0;
        len(rt);
        return t;
    }
    void len(node* n)
    {
        if(n!=nullptr)
        {
            len(n->left);
            if(xx>0)
            {
                t+=n->v-last;
            }
            last=n->v;
            xx+=n->v2;
            len(n->right);
        }
    }
};
class edge
{
public:
    int a,b,c,d;
};
bool cmp(edge x,edge y)
{
    if(x.d==y.d)
        return x.c>y.c;
    return x.d<y.d;
}

int a,b,c,d,n,t;
edge x[NN],y[NN];
treap bt;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    fori(0,n)
    {
        cin>>a>>b>>c>>d;
        x[2*i]={a,c,1,b}; x[2*i+1]={a,c,-1,d};
        y[2*i]={b,d,1,a}; y[2*i+1]={b,d,-1,c};
    }
    sort(x,x+2*n,cmp); sort(y,y+2*n,cmp);
    fori(0,2*n)
    {
        a=bt.len();
        if(x[i].c==1)
        {
            bt.ins(x[i].a,1);
            bt.ins(x[i].b,-1);
        }
        if(x[i].c==-1)
        {
            bt.del(x[i].a,1);
            bt.del(x[i].b,-1);
        }
        b=bt.len();
        t+=abs(a-b);
    }
    fori(0,2*n)
    {
        a=bt.len();
        if(y[i].c==1)
        {
            bt.ins(y[i].a,1);
            bt.ins(y[i].b,-1);
        }
        if(y[i].c==-1)
        {
            bt.del(y[i].a,1);
            bt.del(y[i].b,-1);
        }
        b=bt.len();
        t+=abs(a-b);
    }
    cout<<t;
    return 0;
}