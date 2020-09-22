#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

class node
{
public:
    node* child[2];
    int i;
    node(int index)
    {
        i=index;
        fori(0,2)
            child[i]=nullptr;
    }
};
class trie
{
public:
    node* rt;
    trie()
    {
        rt=new node(INT_MAX);
    }
    void insert(int n,int v)
    {
        node* cur=rt;
        ford(i,30,0)
        {
            if(v&(1<<i))
            {
                if(cur->child[1]==nullptr)
                    cur->child[1]=new node(INT_MAX);
                cur=cur->child[1];
            }
            else
            {
                if(cur->child[0]==nullptr)
                    cur->child[0]=new node(INT_MAX);
                cur=cur->child[0];
            }
        }
        cur->i=min(cur->i,n);
    }
    int find(int v)
    {
        node* cur=rt;
        ford(i,30,0)
        {
            if(v&(1<<i)&&cur->child[1]!=nullptr)
                cur=cur->child[1];
            else if(cur->child[0]!=nullptr)
                cur=cur->child[0];
            else if(cur->child[1]!=nullptr)
                cur=cur->child[1];
            else
                return INT_MAX;
        }
        return cur->i;
    }
};

int n,q,x,a;
trie tr;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>q;
    fori(0,n)
    {
        cin>>x;
        tr.insert(i,x);
    }
    x=0;
    fori(0,q)
    {
        cin>>a; x^=a;
        cout<<tr.find(x)<<"\n";
    }
    return 0;
}