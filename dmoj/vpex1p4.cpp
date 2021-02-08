#include <iostream>
#include <vector>
#include <cstring>
#include <math.h>

using namespace std;

int n, d, s1, s2, a, b;
long long tot1, tot2, ttot1, ttot2;
vector<pair<int, int> > g[100001];
int lca[18][100001], dep[100001];
long long dis[100001];

void dfs(int u, int p){
	for(auto i:g[u]){
		if(i.first!=p){
			dep[i.first]=dep[u]+1;
			dis[i.first]=dis[u]+i.second;
			lca[0][i.first]=u;
			dfs(i.first, u);
		}
	}
}

int qlca(int u, int v){
	if(dep[u]<dep[v]){
		swap(u, v);
	}
	for(int i=log2(n);i>=0;i--){
		if(lca[i][u]!=-1&&dep[lca[i][u]]>=dep[v]){
			u=lca[i][u];
		}
	}
	if(u==v){
		return v;
	}
	for(int i=log2(n);i>=0;i--){
		if(lca[i][u]!=-1&&lca[i][v]!=-1&&lca[i][u]!=lca[i][v]){
			u=lca[i][u];
			v=lca[i][v];
		}
	}
	return lca[0][u];
}

long long qdis(int u, int v){
	int x=qlca(u, v);
	return dis[u]+dis[v]-2*dis[x];
}

int main(){

	memset(lca, -1, sizeof(lca));

	scanf("%d%d", &n, &d);
	
	for(int i=1,u,v,w;i<=n-1;i++){
		scanf("%d%d%d", &u, &v, &w);
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	
	dep[1]=0;
	dfs(1, -1);
	lca[0][1]=1;
	for(int i=1;i<=log2(n)+1;i++){
		for(int j=1;j<=n;j++){
			lca[i][j]=lca[i-1][lca[i-1][j]];
		}
	}
	
	s1=1, s2=1;
	tot1=0, tot2=0;
	for(int i=1;i<=d;i++){
		scanf("%d%d", &a, &b);
		ttot2=tot1+qdis(s1, a)+qdis(a, b);					//s1->a->b =>tt2 + t1
		ttot1=tot1+qdis(s1, b)+qdis(b, a);					//s1->b->a =>tt1 + t1
		ttot2=min(ttot2, tot2+qdis(s2, a)+qdis(a, b));		//s2->a->b =>tt2 + t2
		ttot1=min(ttot1, tot2+qdis(s2, b)+qdis(b, a));		//s2->b->a =>tt1 + t2
		tot1=ttot1, tot2=ttot2;
		s1=a, s2=b;
	}
	
	printf("%lld\n", min(tot1, tot2));

}