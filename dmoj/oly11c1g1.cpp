#include <bits/stdc++.h>
#define fori(a,b) for(long long i=a;i<b;i++)
#define forj(a,b) for(long long j=a;j<b;j++)
#define fork(a,b) for(long long k=a;k<b;k++)
#define ford(i,a,b) for(long long i=a;i>=b;i--)

using namespace std;

class node
{
public:
    long long v,p,sz,n;
    node *left,*right;
    node(long long x)
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
    long long sz(node *n)
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
    long long index(long long v)
    {
        return index(v,rt);
    }
    long long index(long long v,node *n)
    {
        if(n->v>v&&n->left!=nullptr)
            return index(v,n->left);
        else if(n->v>v)
            return 1;
        if(n->v<v&&n->right!=nullptr)
            return index(v,n->right)+sz(n->left)+n->n;
        else if(n->v<v)
            return sz(n->left)+n->n+1;
        return sz(n->left)+1;
    }
};

long long n,l,x,t,sum[100100];
treap st;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>l;
    fori(1,n+1)
    {
        cin>>x;
        if(x>=l)
            sum[i]=sum[i-1]+1;
        else
            sum[i]=sum[i-1]-1;
    }/*
    fori(0,5)
        st.ins(i*2);
    fori(0,10)
        cout<<st.index(i)<<endl;
    cout<<endl;*/
    st.ins(sum[n]);
    ford(i,n-1,0)
    {
        t+=st.rt->sz-st.index(sum[i])+1;
        st.ins(sum[i]);
    }
    cout<<t;
    return 0;
}