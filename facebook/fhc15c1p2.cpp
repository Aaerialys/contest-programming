#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

class node
{
public:
    node* child[26];
    node(int index)
    {
        fori(0,26)
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
    int insert(string s)
    {
        node* cur=rt;
        int x=0;
        fori(0,s.size())
        {
            if(cur->child[s[i]-'a']==nullptr)
                cur->child[s[i]-'a']=new node(INT_MAX);
            else if(i<s.size()-1)
                x++;
            cur=cur->child[s[i]-'a'];
        }
        return x;
    }
    void del(node* cur)
    {
        fori(0,26)
            if(cur->child[i]!=nullptr)
                del(cur->child[i]);
        if(cur==rt)
        {
            fori(0,26)
                cur->child[i]=nullptr;
        }
        else
            delete cur;

    }
};

int t,n,s;
trie tr;
string str;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>t;
    forj(0,t)
    {
        cin>>n; s=0;
        fori(0,n)
        {
            cin>>str;
            s+=tr.insert(str)+1;
        }
        cout<<"Case #"<<j+1<<": "<<s<<"\n";
        tr.del(tr.rt);
    }
    return 0;
}