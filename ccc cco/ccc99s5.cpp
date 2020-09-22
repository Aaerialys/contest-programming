#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int n,x,le[10],nu[26];
double a,b,c;
string p,q,r;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    fork(0,n)
    {
        x=0;
        fori(0,26)
            nu[i]=-1;
        fori(0,10)
            le[i]=-1;
        cin>>p>>q>>r;
        fori(0,p.size())
            if(nu[p[i]-'A']==-1)
            {
                le[x]=p[i]-'A';
                nu[p[i]-'A']=x;
                x++;
            }
        fori(0,q.size())
            if(nu[q[i]-'A']==-1)
            {
                le[x]=q[i]-'A';
                nu[q[i]-'A']=x;
                x++;
            }
        fori(0,r.size())
            if(nu[r[i]-'A']==-1)
            {
                le[x]=r[i]-'A';
                nu[r[i]-'A']=x;
                x++;
            }
        sort(le,le+10);
        do
        {
            a=b=c=0;
            fori(0,10)
                if(le[i]!=-1)
                    nu[le[i]]=i;
            if(nu[p[0]-'A']==0||nu[q[0]-'A']==0||nu[r[0]-'A']==0)
                continue;
            fori(0,p.size())
            {
                a*=10;
                a+=nu[p[i]-'A'];
            }
            fori(0,q.size())
            {
                b*=10;
                b+=nu[q[i]-'A'];
            }
            fori(0,r.size())
            {
                c*=10;
                c+=nu[r[i]-'A'];
            }
            if(c/abs(a+b-c)>1e13)
            {
                fori(0,p.size())
                    cout<<nu[p[i]-'A'];
                cout<<"\n";
                fori(0,q.size())
                    cout<<nu[q[i]-'A'];
                cout<<"\n";
                fori(0,r.size())
                    cout<<nu[r[i]-'A'];
                cout<<"\n";
                break;
            }
        } while(next_permutation(le,le+10));
    }
    return 0;
}