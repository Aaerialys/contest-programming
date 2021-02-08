#include <bits/stdc++.h>
#define fori(x) for (int i=0; i<(x); i++)
#define forj(x) for (int j=0; j<(x); j++)
#define forit(x) for (int i=1; i<=(x); i++)
#define forjt(x) for (int j=1; j<=(x); j++)

using namespace std;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int w,n,d=0;
    cin>>w>>n;
    w--;
    d=w;
    cout<<"Sun Mon Tue Wed Thr Fri Sat"<<"\n";
    fori(w)
    {
        cout<<"    ";
    }
    forit(n-1)
    {
        if(d==6)
        {
            if(i>=100)
            {
                d++;
                cout<<i;
            }
            else if(i>=10)
            {
                d++;
                cout<<" "<<i;
            }
            else
            {
                d++;
                cout<<"  "<<i;
            }
            d=0;
            cout<<"\n";
        }
        else if(i>=100)
        {
            d++;
            cout<<i<<" ";
        }
        else if(i>=10)
        {
            d++;
            cout<<" "<<i<<" ";
        }
        else
        {
            d++;
            cout<<"  "<<i<<" ";
        }
    }
    if(n>=100)
    {
        d++;
        cout<<n;
    }
    else if(n>=10)
    {
        d++;
        cout<<" "<<n;
    }
    else
    {
        d++;
        cout<<"  "<<n;
    }
    cout<<"\n";
    return 0;
}