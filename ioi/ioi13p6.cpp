#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define seto(x,i) memset(x,i,sizeof x)
#define inf 0x3f3f3f3f;
#define INF 0x3f3f3f3f3f3f3f3f;
#define pf first
#define ps second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

ll gcd(ll a,ll b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
const int N=1e9+10;
int sz,SZ=1;
class node
{
public:
    int pos,p,l,r;
    ll v,rv;
    node *left,*right;
    node(int x,ll y)
    {
        l=r=pos=x;
        v=rv=y;
        p=rand();
        left=right=nullptr;
    }
};
class treap
{
public:
    node *rt;
    int lc,rc;
    treap()
    {
        rt=nullptr;
        lc=rc=0;
    }
    ll getv(node *n)
    {
        if(n!=nullptr)
            return n->rv;
        return 0;
    }
    int getl(node *n)
    {
        if(n!=nullptr)
            return n->l;
        return inf;
    }
    int getr(node *n)
    {
        if(n!=nullptr)
            return n->r;
        return -1;
    }
    void updsz(node *n)
    {
        if(n!=nullptr)
        {
            n->rv=gcd(gcd(getv(n->left),getv(n->right)),n->v);
            n->l=min(n->pos,getl(n->left));
            n->r=max(n->pos,getr(n->right));
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
    void ins(int pos,ll v)
    {
        if(rt==nullptr)
            rt=new node(pos,v);
        else
            ins(pos,v,rt);
    }
    void ins(int pos,ll v,node *&n)
    {
        if(pos==n->pos)
            n->v=v;
        else if(pos<n->pos)
        {
            if(n->left==nullptr)
                n->left=new node(pos,v);
            else
                ins(pos,v,n->left);
            if(n->left->p<n->p)
                lrot(n);
        }
        else if(pos>n->pos)
        {
            if(n->right==nullptr)
                n->right=new node(pos,v);
            else
                ins(pos,v,n->right);
            if(n->right->p<n->p)
                rrot(n);
        }
        updsz(n);
    }
    ll query(int ql,int qr)
    {
        return query(ql,qr,rt);
    }
    ll query(int ql,int qr,node *n)
    {
        if(n==nullptr||ql>n->r||qr<n->l)
            return 0;
        if(n->l>=ql&&n->r<=qr)
            return getv(n);
        if(n->pos==ql&&n->pos==qr)
            return n->v;
        if(qr<n->pos)
            return query(ql,qr,n->left);
        if(qr<=n->pos)
            return gcd(query(ql,n->pos-1,n->left),n->v);
        if(ql>n->pos)
            return query(ql,qr,n->right);
        if(ql>=n->pos)
            return gcd(query(n->pos+1,qr,n->right),n->v);
        return gcd(gcd(query(ql,n->pos-1,n->left),query(n->pos+1,qr,n->right)),n->v);
    }
};
treap tree[400000];

void update(int x,int y,ll v,int num,int l,int r)
{
    if(l==x&&r==x)
    {
        tree[num].ins(y,v);
        return;
    }
    int mid=(l+r)/2;
    if(x<=mid)
    {
        if(tree[num].lc==0)
        {
            tree[num].lc=++SZ;
        }
        update(x,y,v,tree[num].lc,l,mid);
    }
    if(x>mid)
    {
        if(tree[num].rc==0)
        {
            tree[num].rc=++SZ;
        }
        update(x,y,v,tree[num].rc,mid+1,r);
    }
    tree[num].ins(y,gcd(tree[tree[num].lc].query(y,y),tree[tree[num].rc].query(y,y)));
}
void tupdate(int x,int y,ll v)
{
    update(x,y,v,1,1,N);
}
ll query(int x1,int x2,int y1,int y2,int num,int l,int r)
{
    if(num==0)
        return 0;
    if(l==x1&&r==x2)
        return tree[num].query(y1,y2);
    int mid=(l+r)/2;
    if(x2<=mid)
        return query(x1,x2,y1,y2,tree[num].lc,l,mid);
    if(x1>mid)
        return query(x1,x2,y1,y2,tree[num].rc,mid+1,r);
    return gcd(query(x1,mid,y1,y2,tree[num].lc,l,mid),query(mid+1,x2,y1,y2,tree[num].rc,mid+1,r));
}
ll query(int x1,int x2,int y1,int y2)
{
    return query(x1,x2,y1,y2,1,1,N);
}

void init(int R,int C)
{
    return;
}
void update(int P,int Q,ll K)
{
    tupdate(P+1,Q+1,K);
}
ll calculate(int P,int Q,int U,int V)
{
    return query(P+1,U+1,Q+1,V+1);
}

ll q,x,a,b,c,d;
vector<ll> ans;

treap test;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("02.st-2-dense-3.in", "r", stdin);
    cin>>a>>b>>q;
    init(a,b);
    fori(0,q)
    {
        cin>>x;
        if(x==1)
        {
            cin>>a>>b>>c;
            update(a,b,c);
        }
        if(x==2)
        {
            cin>>a>>b>>c>>d;
            ans.push_back(calculate(a,b,c,d));
            //cout<<ans.back()<<endl;
            if(i%10000==0)
                cout<<i<<endl;
        }
    }
    //cout<<SZ<<" "<<sz<<endl;
    freopen("02.st-2-dense-3.out", "r", stdin);
    fori(0,ans.size())
    {
        cin>>a; //cout<<a<<endl;/*
        if(a!=ans[i])
            cout<<i<<" "<<ans[i]<<" "<<a<<endl;//*
    }//*/
    return 0;
}