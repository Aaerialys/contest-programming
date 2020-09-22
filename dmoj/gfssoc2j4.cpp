#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int n,q,a,b,tot;
    scanf("%d",&n);
    scanf("%d",&q);
    int rat[n+1];
    rat[0]=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&rat[i]);
        rat[i]+=rat[i-1];
    }
    tot=rat[n];
    for(int i=0;i<q;i++)
    {
        scanf("%d",&a);
        scanf("%d",&b);
        printf("%d\n",tot-rat[b]+rat[a-1]);
    }
    return 0;
}