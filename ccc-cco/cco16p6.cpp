#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

class node
{
public:
    long long v,p,sz,lz,n,sm;
    node *left, *right;
    node(long long x,int num)
    {
        sm=v=x;
        lz=0;
        sz=n=num;
        p=rand();
        left=right=nullptr;
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
    long long lz(node *n)
    {
        if(n!=nullptr)
            return n->lz;
        return 0;
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
            n->v+=n->lz;
            if(n->left!=nullptr)
                n->left->lz+=n->lz;
            if(n->right!=nullptr)
                n->right->lz+=n->lz;
            n->sm=sm(n->left)+lz(n->left)*sz(n->left)+sm(n->right)+lz(n->right)*sz(n->right)+(n->v)*(n->n);
            n->lz=0;
        }
    }
    void lrot(node *&n)
    {
        updsz(n); updsz(n->left); updsz(n->right);
        node *temp=n->left; n->left=temp->right; temp->right=n;
        updsz(n); updsz(temp);
        n=temp;
    }
    void rrot(node *&n)
    {
        updsz(n); updsz(n->left); updsz(n->right);
        node *temp=n->right; n->right=temp->left; temp->left=n;
        updsz(n); updsz(temp);
        n=temp;
    }
    void ins(long long x,int num)
    {
        if(num==0)
            return;
        if(rt==nullptr)
            rt=new node(x,num);
        else
            ins(x,num,rt);
    }
    void ins(long long x,int num,node *&n)
    {
        updsz(n);
        if(x==n->v)
            (n->n)+=num;
        else if(x<n->v)
        {
            if(n->left==nullptr)
                n->left=new node(x,num);
            else
                ins(x,num,n->left);
            if(n->left->p<n->p)
                lrot(n);
        }
        else if(x>n->v)
        {
            if(n->right==nullptr)
                n->right=new node(x,num);
            else
                ins(x,num,n->right);
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
        updsz(n);
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
                updsz(n->left); updsz(n->right);
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
    long long mins(int x)
    {
        return mins(x,rt);
    }
    long long mins(int x,node *n)
    {
        if(n==nullptr)
            return 0;
        updsz(n); updsz(n->left); updsz(n->right);
        if(sz(n->left)>=x)
            return mins(x,n->left);
        else if(sz(n->left)+n->n>=x)
            return sm(n->left)+(n->v)*(x-sz(n->left));
        return mins(x-sz(n->left)-n->n,n->right)+sm(n->left)+(n->v)*(n->n);
    }
    void delarg(int x)
    {
        delarg(x,rt);
    }
    void delarg(int x,node *&n)
    {
        updsz(n);
        if(n!=nullptr)
        {
            updsz(n->left);
            updsz(n->right);
        }
        if(sz(n)<=x)
        {
            n=nullptr;
            return;
        }
        if(sz(n->right)>=x)
        {
            delarg(x,n->right);
            updsz(n);
            return;
        }
        x-=sz(n->right);
        n->right=nullptr;
        if(n->n>x)
        {
            n->n-=x;
            updsz(n);
            return;
        }
        if(n->n<x)
            delarg(x-n->n,n->left);
        n->n=0;
        del(rt,n->v);
        return;

    }
    void inc()
    {
        if(rt!=nullptr)
            rt->lz++;
    }
};
treap tr;
long long n,k,x,y,vote[1000010],coin[1000010];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    fori(0,n)
    {
        cin>>vote[i];
        vote[i]--;
    }
    fori(0,n)
    {
        x=tr.mins(vote[i]);
        x+=vote[i];
        if(x>k)
            coin[i]=-1;
        else
        {
            coin[i]=k-x;
            tr.delarg(i-vote[i]);
            tr.inc();
            tr.ins(0,i-vote[i]);
        }
        tr.ins(coin[i],1);
    }
    fori(0,n)
        cout<<coin[i]<<"\n";
    return 0;
}