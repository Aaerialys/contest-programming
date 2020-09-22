#include <stdio.h>

int n,q,u,v;
unsigned char p[6000000][3];

int main(){
    scanf("%d",&n); scanf("%d",&q);
    for(int i=1;i<n;i++){
        scanf("%d",&v); v--;
        p[i][0]=v&255; p[i][1]=(v>>8)&255; p[i][2]=(v>>16)&255;
    }
    while(q--){
        scanf("%d",&u); scanf("%d",&v); u--; v--;
        while(u!=v){
            if(u>v) u=p[u][0]|(p[u][1]<<8)|(p[u][2]<<16);
            else v=p[v][0]|(p[v][1]<<8)|(p[v][2]<<16);
        }
        printf("%d\n",v+1);
    }
    return 0;
}
/**
e[i+1]=sum[e[j]]/i+1

=((e[i]-1)*(i-1)+e[i])/i+1
=(e[i]*i-i+1)/i+1
=e[i]-1+1/i+1
=e[i]+1/i
e[i]=ln(i);
*/