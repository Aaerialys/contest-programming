#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

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
    node* check(int x)
    {
        return check(x,rt);
    }
    node* check(int x,node *n)
    {
        if(n==nullptr)
            return nullptr;
        if(x<n->v)
            return check(x,n->left);
        if(x>n->v)
            return check(x,n->right);
        return n;
    }
    node* mini(node* n)
    {
        if(n->left!=nullptr)
            return mini(n->left);
        return n;
    }
    node* maxi(node* n)
    {
        if(n->right!=nullptr)
            return mini(n->right);
        return n;
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
        return index(v,rt);
    }
    int index(int v,node *n)
    {
        if(n==nullptr)
            return INT_MIN;
        if(n->v>v)
            return index(v,n->left);
        if(n->v<v)
            return index(v,n->right)+sz(n->left)+n->n;
        return sz(n->left)+1;
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
    void inorder()
    {
        if(rt!=nullptr)
            inorder(rt);
    }
    void inorder(node* n)
    {
        if(n!=nullptr)
        {
            inorder(n->left);
            fori(0,n->n)
                cout<<n->v<<" ";
            inorder(n->right);
        }
    }
    void preorder()
    {
        if(rt!=nullptr)
            preorder(rt);
    }
    void preorder(node* n)
    {
        if(n!=nullptr)
        {
            fori(0,n->n)
                cout<<n->v<<"\n";
            preorder(n->left); preorder(n->right);
        }
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
                cout<<n->v<<"\n";
        }
    }
    void levelorder()
    {
        queue<node*>toV;
        node *temp;
        toV.push(rt);
        while(!toV.empty())
        {
            temp=toV.front(); toV.pop();
            if(temp==nullptr)
            {
                cout<<". ";
            }
            else
            {
                cout<<temp->v<<"."<<temp->sz<<"."<<temp->p<<" ";
                toV.push(temp->left); toV.push(temp->right);
            }
        }
    }
};

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n,m,a,las=0;
    char ch;
    treap t;
    cin>>n>>m;
    fori(0,n)
    {
        cin>>a;
        t.ins(a);
    }
    fori(0,m)
    {
        cin>>ch>>a;
        a=(a^las);
        if(ch=='I')
            t.ins(a);
        if(ch=='R')
            t.del(a);
        if(ch=='S')
        {
            las=t.element(a);
            cout<<las<<"\n";
        }
        if(ch=='L')
        {
            las=max(t.index(a),-1);
            cout<<las<<"\n";
        }
    }
    t.inorder();
    return 0;
}