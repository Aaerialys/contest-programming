#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

queue<int> temp;

class node
{
public:
    int v,p,sz,n;
    node *left, *right;
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
    int element(int x)
    {
        if(x<=0||x>rt->sz)
            return -1;
        return element(x,rt)->v;
    }
    node* element(int x, node *n)
    {
        if(sz(n->left)>=x)
            return element(x,n->left);
        else if(sz(n->left)+n->n>=x)
            return n;
        return element(x-sz(n->left)-n->n,n->right);
    }
    void postorder()
    {
        if(rt!=nullptr)
            postorder(rt);
    }
    void postorder(node* n)
    {
        if(n!=nullptr)
        {
            postorder(n->left); postorder(n->right);
            fori(0,n->n)
                temp.push(n->v);//cout<<n->v<<"\n";
            del(n->v);
        }
    }
};

int V;
int parent[100001];
treap gr[100001];
int p,q,r,s,t;

class djSet
{
public:
    djSet(int v)
    {
        V=v;
        for(int i=0;i<V;i++)
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
        if(gr[x].sz(gr[x].rt)<gr[y].sz(gr[y].rt))
            swap(x,y);
        if(x!=y)
        {
            parent[y]=x;
            gr[y].postorder();
            while(!temp.empty())
            {
                gr[x].ins(temp.front());
                temp.pop();
            }
        }
    }
};

int n,m,a,b,rnk[100001];
char c;
djSet grp(100001);

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    fori(0,n)
    {
        cin>>a;
        gr[i].ins(a);
        rnk[a]=i+1;
    }
    fori(0,m)
    {
        cin>>a>>b;
        a--; b--;
        grp.link(a,b);
    }
    cin>>m;
    fori(0,m)
    {
        cin>>c>>a>>b;
        a--; b--;
        if(c=='B')
            grp.link(a,b);
        if(c=='Q')
        {
            a=grp.lead(a);
            a=gr[a].element(b+1);
            if(a==-1)
                cout<<"-1\n";
            else
                cout<<rnk[a]<<"\n";
        }
    }
    return 0;
}