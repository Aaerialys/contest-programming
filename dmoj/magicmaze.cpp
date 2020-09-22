#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define seto(x,i) memset(x,i,sizeof x)
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
#define pf first
#define ps second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int N=100010,P=168;
int n,q,x1,x2,Y1,y2,t,r[P][N],c[P][N],p[P]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541,547,557,563,569,571,577,587,593,599,601,607,613,617,619,631,641,643,647,653,659,661,673,677,683,691,701,709,719,727,733,739,743,751,757,761,769,773,787,797,809,811,821,823,827,829,839,853,857,859,863,877,881,883,887,907,911,919,929,937,941,947,953,967,971,977,983,991,997};
vector<int> rp[N],cp[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("","r",stdin);
    cin>>n>>q;
    fori(1,n+1)
    {
        cin>>t;
        forj(0,P)
        {
            r[j][i]=r[j][i-1];
            if(t%p[j]==0)
            {
                r[j][i]++;
                rp[i].push_back(j);
            }
        }
    }
    fori(1,n+1)
    {
        cin>>t;
        forj(0,P)
        {
            c[j][i]=c[j][i-1];
            if(t%p[j]==0)
            {
                c[j][i]++;
                cp[i].push_back(j);
            }
        }
    }
    fori(0,q)
    {
        cin>>x1>>Y1>>x2>>y2; t=-1; n=0;
        for(auto j:cp[y2])
            if(t<p[j]&&(r[j][x1]-r[j][x1-1]==1||c[j][y2]-c[j][Y1-1]==y2-Y1+1||c[j][Y1]-c[j][Y1-1]==1&&r[j][x2]-r[j][x1-1]>0))
                t=p[j];
        for(auto j:rp[x2])
            if(t<p[j]&&(c[j][Y1]-c[j][Y1-1]==1||r[j][x2]-r[j][x1-1]==x2-x1+1||r[j][x1]-r[j][x1-1]==1&&c[j][y2]-c[j][Y1-1]>0))
                t=p[j];
        /*forj(0,P)
            if(//(r[j][x1]-r[j][x1-1]==1||c[j][y2]-c[j][Y1-1]==y2-Y1+1)&&c[j][y2]-c[j][y2-1]==1
               ||r[j][x1]-r[j][x1-1]==1&&r[j][x2]-r[j][x2-1]==1&&c[j][y2]-c[j][Y1-1]>0
               ||(c[j][Y1]-c[j][Y1-1]==1||r[j][x2]-r[j][x1-1]==x2-x1+1)&&r[j][x2]-r[j][x2-1]==1
               //||c[j][Y1]-c[j][Y1-1]==1&&c[j][y2]-c[j][y2-1]==1&&r[j][x2]-r[j][x1-1]>0)
            {
                t=p[j];
                n++;
                if(n>5)
                    break;
            }*/
        cout<<t<<"\n";
    }
    return 0;
}