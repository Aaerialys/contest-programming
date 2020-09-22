#include <bits/stdc++.h>
#define sc(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
#define MM 1501
std::vector<short> adj[MM];
std::queue<short> q;
short dis[MM],N,M,K,a,b,cnt,cur,i;
int main(){
    sc(N); sc(M); sc(K);
    while(M--){
        sc(a); sc(b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(i = 1; i <= N; i++){
        cnt = 1;
        memset(dis,0,sizeof(dis));
        q.push(i); dis[i] = 1;
        while(!q.empty()){
            cur = q.front(); q.pop();
            if(dis[cur] <= K){
                for(int u: adj[cur]){
                    if(!dis[u]){
                        dis[u] = dis[cur]+1;
                        q.push(u);
                        cnt++;
                    }
                }
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}