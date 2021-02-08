#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)
#define ford(i,a,b) for(int i=a;i>=b;i--)

using namespace std;

int k,lx,rx,ly,ry,mx,my,a,b,c;

int main()
{
    cin>>rx>>ry>>k; lx=ly=1; k=INT_MAX;
    while(lx<rx||ly<ry)
    {
        mx=(lx+rx)/2; my=(ly+ry)/2;
        cout<<"? "<<mx<<" "<<my<<endl;
        cin>>a; b = INT_MAX; c = INT_MAX;
        if(lx < rx){
            cout<<"? "<<mx+1<<" "<<my<<endl;
            cin>>b;
            if(b<a)
                lx=mx+1;
            else
                rx=mx;
        }
        if(ly < ry){
            cout<<"? "<<mx<<" "<<my+1<<endl;
            cin>>c;
            if(c<a)
                ly=my+1;
            else
                ry=my;
        }
        k=min(k,min(a,min(b,c)));
    }
    cout<<"? "<<lx<<" "<<ly<<endl;
    cin >> k;
    cout<<"! "<<k<<endl;
    return 0;
}
//binary search minimum (median)