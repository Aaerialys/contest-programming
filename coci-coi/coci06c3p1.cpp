#include <bits/stdc++.h>
#define fori(a,b) for(int i=a;i<b;i++)
#define forj(a,b) for(int j=a;j<b;j++)
#define fork(a,b) for(int k=a;k<b;k++)

using namespace std;

int x,hat[10];

int main()
{
    fori(0,9)
        cin>>hat[i];
    sort(hat,hat+9);
    do
    {
        x=0;
        fori(0,7)
            x+=hat[i];
        if(x==100)
        {
            fori(0,7)
                cout<<hat[i]<<"\n";
            return 0;
        }

    }while(next_permutation(hat,hat+9));
    return 0;
}